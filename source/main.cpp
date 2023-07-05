#include <tonc.h>
#include <string>

#include "debug.h"
#include "mirror.h"
#include "gba_flash.h"
#include "interrupt.h"
#include "gb_link.h"
#include "gameboy_colour.h"
#include "LinkGPIO.h"
#include "pokemon.h"
#include "random.h"

/*TODO:
- Add Pokemon to Pokedex
- Enable ribbon viewing
- Implement shiny
- Randomize base seed
- Double check that returns false when PC is full BEFORE injecting
- Fix abilities
- Match number of injects to party size
- Fix coruption
*/

// This file is autogenerated from the file in the graphics folder
#include "metr.h"

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

byte party_data[441] = {0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0xFF, 0x25, 0xDA, 155, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x9B, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x9B, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x9B, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x9B, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x9B, 0x0, 0x21, 0x2B, 0x0, 0x0, 0x25, 0xDA, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x21, 0x23, 0x1E, 0x0, 0x0, 0x46, 0x0, 0x85, 0x81, 0x5, 0x0, 0x0, 0x0, 0x13, 0x0, 0x13, 0x0, 0x0A, 0x0, 0x9, 0x0, 0x0B, 0x0, 0x0B, 0x0, 0x0A, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x8A, 0x91, 0x88, 0x92, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50, 0x82, 0x98, 0x8D, 0x83, 0x80, 0x90, 0x94, 0x88, 0x8B, 0x50, 0x50};

Poke_Random poke_rand(0x12162001);

Pokemon party[6] = {};

vu8 pkmn[480] = {
	0x5C, 0xF2, 0x9B, 0x70, 0x9B, 0x2A, 0x81, 0xE4, 0xBB, 0xC6, 0xBC, 0xBF, 0xCC, 0xCE, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0x0E, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94, 0xC7, 0x60, 0x1B, 0xB6,
	0xBD, 0xC2, 0x51, 0x85, 0xC7, 0xD8, 0x1A, 0x94, 0x2A, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94,
	0xC8, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94, 0xC7, 0xD8, 0x1A, 0x94,

	0xD1, 0xA8, 0x64, 0x28, 0x9B, 0x2A, 0x81, 0xE4, 0xBC, 0xBB, 0xCC, 0xCE, 0xFF, 0xCE, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0x83, 0x82, 0xE5, 0xCC, 0x4A, 0x82, 0xE5, 0xCC, 0x4A, 0x82, 0xE5, 0xCC, 0xA7, 0x82, 0xE5, 0xCC,
	0x4A, 0x82, 0xE5, 0xCC, 0x45, 0x82, 0xE5, 0xCC, 0x4A, 0x3A, 0xE4, 0xEE, 0x30, 0x98, 0xAE, 0xDD,
	0x4A, 0x82, 0xE5, 0xCC, 0x4A, 0x82, 0xE5, 0xCC, 0x4A, 0x82, 0xE5, 0xCC, 0x4A, 0x82, 0xE5, 0xCC,

	0x4E, 0x5B, 0xB7, 0xF3, 0x9B, 0x2A, 0x81, 0xE4, 0xBD, 0xBB, 0xCC, 0xCE, 0xBF, 0xCC, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0xD5, 0xC9, 0x37, 0x35, 0xAF, 0x6B, 0x7D, 0x06, 0xD5, 0x71, 0x36, 0x17, 0xD5, 0x71, 0x36, 0x17,
	0xD5, 0x71, 0x36, 0x17, 0xD5, 0x71, 0x36, 0x17, 0x1C, 0x71, 0x36, 0x17, 0xD5, 0x71, 0x36, 0x17,
	0xD5, 0x71, 0x36, 0x17, 0x38, 0x71, 0x36, 0x17, 0xD5, 0x71, 0x36, 0x17, 0xDA, 0x71, 0x36, 0x17,

	0x5F, 0x80, 0x16, 0xBB, 0x9B, 0x2A, 0x81, 0xE4, 0xBE, 0xBB, 0xD1, 0xC8, 0xFF, 0xCC, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0xC4, 0xAA, 0x97, 0x5F, 0xC4, 0xAA, 0x97, 0x5F, 0xC4, 0xAA, 0x97, 0x5F, 0x29, 0xAA, 0x97, 0x5F,
	0xC4, 0xAA, 0x97, 0x5F, 0xCB, 0xAA, 0x97, 0x5F, 0xC4, 0x12, 0x96, 0x7D, 0xBE, 0xB0, 0xDC, 0x4E,
	0xC4, 0xAA, 0x97, 0x5F, 0x0D, 0xAA, 0x97, 0x5F, 0xC4, 0xAA, 0x97, 0x5F, 0xC4, 0xAA, 0x97, 0x5F,

	0x14, 0x43, 0x7A, 0xCE, 0x9B, 0x2A, 0x81, 0xE4, 0xBF, 0xCC, 0xC3, 0xC5, 0xFF, 0xCC, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0x46, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A, 0x8F, 0xD1, 0xFA, 0x08,
	0xF5, 0x73, 0xB0, 0x3B, 0x8F, 0x69, 0xFB, 0x2A, 0x62, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A,
	0x80, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A, 0x8F, 0x69, 0xFB, 0x2A,

	0xF5, 0x91, 0x98, 0x00, 0x9B, 0x2A, 0x81, 0xE4, 0xC0, 0xCC, 0xBB, 0xC8, 0xC5, 0xFF, 0xFF, 0x00,
	0x00, 0x00, 0x02, 0x02, 0xBB, 0xCF, 0xCD, 0xCE, 0xC3, 0xC8, 0xFF, 0x00, 0x8B, 0x07, 0x00, 0x00,
	0xA7, 0xBB, 0x19, 0xE4, 0x6E, 0xBB, 0x19, 0xE4, 0x6E, 0xBB, 0x19, 0xE4, 0x6E, 0x03, 0x18, 0xC6,
	0x14, 0xA1, 0x52, 0xF5, 0x6E, 0xBB, 0x19, 0xE4, 0x6E, 0xBB, 0x19, 0xE4, 0x6E, 0xBB, 0x19, 0xE4,
	0x6E, 0xBB, 0x19, 0xE4, 0x83, 0xBB, 0x19, 0xE4, 0x6E, 0xBB, 0x19, 0xE4, 0x61, 0xBB, 0x19, 0xE4};

void load_sprite(void)
{
	// Load tiles and palette of sprite into video and palete RAM
	memcpy32(&tile_mem[4][0], metrTiles, metrTilesLen / 4);
	memcpy32(pal_obj_mem, metrPal, metrPalLen / 4);

	oam_init(obj_buffer, 128);

	OBJ_ATTR *metr = &obj_buffer[0];
	obj_set_attr(metr,
				 ATTR0_SQUARE,			// Square, regular sprite
				 ATTR1_SIZE_64,			// 64x64 pixels,
				 ATTR2_PALBANK(0) | 0); // palette index 0, tile index 0

	// Set position
	obj_set_pos(metr, 176, 96);

	oam_copy(oam_mem, obj_buffer, 1); // Update first OAM object
}

void load_pokemon(byte *party_array, int gen){

	for (int i = 0; i < 6; i++)
	{
		party[i].load_data(2, 0, &party_array[0]);
		poke_rand.next_frame();
		party[i].convert_to_gen_three(poke_rand.get_rand());
	}
}

int main(void)
{

	linkGPIO->reset();

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;
	tte_init_se_default(0, BG_CBB(0) | BG_SBB(31));

	irq_init(NULL);
	irq_enable(II_VBLANK);

	flash_init(FLASH_SIZE_128KB);
	initalize_memory_locations();

	//load_sprite();
	load_pokemon(&party_data[0], 2);

	int frame = 0;
	int arr = 0;

	char str[128] = {'\0'};
	bool print = false;

	while (1)
	{
		u16 keys = ~REG_KEYS & KEY_ANY;
		poke_rand.next_frame();

		vid_vsync();
		key_poll();
		if (key_released(KEY_UP))
		{
			arr++;
			if (arr == 14)
			{
				arr = 0;
			}
		}
		if (key_released(KEY_DOWN))
		{
			arr--;
			if (arr == -1)
			{
				arr = 13;
			}
		}
		if (key_released(KEY_A))
		{
			insert_pokemon(&party[0], 6);
			print = true;
		}

		if (key_released(KEY_START))
		{
			setup();
			loop();
		}

		tte_erase_screen();

		tte_set_pos(0, 0);
		printValueAt(memory_section_array[arr] + 0xFF4);

		tte_set_pos(0, 10);
		sprintf(str, "[%c-%X] R:%X", mem_name, arr, poke_rand.get_rand());
		tte_write(str);

		if (print)
		{
			tte_set_pos(0, 20);
			tte_write("Pokemon Injected!");
			tte_set_pos(0,30);
			for(int i = 0; i < 80; i++){
				tte_write(intToHex(party[0].get_gen_3_data(i)).c_str());
				tte_write(" ");
			}
			tte_set_pos(0, 110);
			for(int i = 0; i < 49; i++){
				tte_write(intToHex(party[0].get_unencrypted_data(i)).c_str());
				tte_write(" ");
			}

			
		}
			

		tte_set_pos(0, 30);

		frame++;
		VBlankIntrWait();
	}
}

/*Credits:
https://github.com/laqieer/libsavgba
https://github.com/rodri042/gba-link-connection
arduino-boy

Notes:
- GBA and GBC link cables are different, that's why it didn't work initally on mGBA
*/
