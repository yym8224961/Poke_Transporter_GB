#include <tonc.h>
#include "script.h"
#include "flash_mem.h"
#include "gba_flash.h"
#include "script_builder.h"

static u32 wonder_card[0x14E] = {
    0xFC, 0x85, 0x00, 0x00, 0xE8, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBB, 0xCF, 0xCC, 0xC9, 0xCC, 0xBB, 0xCE, 0xC3, 0xBD, 0xC5, 0xBF, 0xCE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBF, 0xEC, 0xD7, 0xDC, 0xD5, 0xE2, 0xDB, 0xD9, 0x00, 0xBD, 0xD5, 0xE6, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0xE3, 0x00, 0xE8, 0xE3, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xE7, 0xD9, 0xD7, 0xE3, 0xE2, 0xD8, 0x00, 0xDA, 0xE0, 0xE3, 0xE3, 0xE6, 0x00, 0xE3, 0xDA, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xCA, 0xC9, 0xC5, 0x1B, 0xC7, 0xC9, 0xC8, 0x00, 0x00, 0x00, 0xBD, 0xBF, 0xC8, 0xCE, 0xBF, 0xCC, 0x00, 0xD5, 0xE2, 0xD8, 0x00, 0xE1, 0xD9, 0xD9, 0xE8, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xD8, 0xD9, 0xE0, 0xDD, 0xEA, 0xD9, 0xE6, 0xED, 0x00, 0xE4, 0xD9, 0xE6, 0xE7, 0xE3, 0xE2, 0x00, 0xDD, 0xE2, 0x00, 0x00, 0xDB, 0xE6, 0xD9, 0xD9, 0xE2, 0xAD, 0x00, 0xCC, 0xD9, 0xD7, 0xD9, 0xDD, 0xEA, 0xD9, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xBB, 0xCF, 0xCC, 0xC9, 0xCC, 0xBB, 0xCE, 0xC3, 0xBD, 0xC5, 0xBF, 0xCE, 0x00, 0xD5, 0xE2, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0xDC, 0xD9, 0xE2, 0x00, 0xE7, 0xD5, 0xEA, 0xD9, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xDB, 0xD5, 0xE1, 0xD9, 0xAB, 0xAB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBE, 0xE3, 0x00, 0xE2, 0xE3, 0xE8, 0x00, 0xE8, 0xE3, 0xE7, 0xE7, 0x00, 0xE8, 0xDC, 0xDD, 0xE7, 0x00, 0xBF, 0xEC, 0xD7, 0xDC, 0xD5, 0xE2, 0xDB, 0xD9, 0x00, 0xBD, 0xD5, 0xE6, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD6, 0xD9, 0xDA, 0xE3, 0xE6, 0xD9, 0x00, 0xE6, 0xD9, 0xD7, 0xD9, 0xDD, 0xEA, 0xDD, 0xE2, 0xDB, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xBB, 0xCF, 0xCC, 0xC9, 0xCC, 0xBB, 0xCE, 0xC3, 0xBD, 0xC5, 0xBF, 0xCE, 0xAB, 0xAB, 0x00, 0x00, 0x00, 0x00, 0x00};
/*
static u32 script[0x3EC] = {
    0xEA, 0xA6, 0x00, 0x00, 0x33, 0xFF, 0xFF, 0xFF, 0xB8, 0x58, 0x02, 0x00, 0x08, 0x6A, 0x5A, 0x2B, 0x3A, 0x01, 0xBB, 0x01, 0xBC, 0x02, 0x00, 0x08, 0x2B, 0xAD, 0x01, 0xBB, 0x01, 0xBC, 0x02, 0x00, 0x08, 0x47, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x01, 0x00, 0xBB, 0x01, 0xBC, 0x02, 0x00, 0x08, 0xBD, 0xC5, 0x02, 0x00, 0x08, 0x66, 0x6D, 0x46, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x00, 0x00, 0xBB, 0x01, 0xB3, 0x02, 0x00, 0x08, 0x1A, 0x00, 0x80, 0x73, 0x01, 0x1A, 0x01, 0x80, 0x01, 0x00, 0x09, 0x00, 0x29, 0xD5, 0x08, 0x29, 0x3A, 0x01, 0xBD, 0x22, 0x03, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xBD, 0xB3, 0x03, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xBD, 0x86, 0x03, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xCE, 0xDC, 0xD5, 0xE2, 0xDF, 0x00, 0xED, 0xE3, 0xE9, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xE9, 0xE7, 0xDD, 0xE2, 0xDB, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xC7, 0xD3, 0xCD, 0xCE, 0xBF, 0xCC, 0xD3, 0xFE, 0xC1, 0xC3, 0xC0, 0xCE, 0x00, 0xCD, 0xED, 0xE7, 0xE8, 0xD9, 0xE1, 0xAD, 0xFB, 0xD3, 0xE3, 0xE9, 0x00, 0xE1, 0xE9, 0xE7, 0xE8, 0x00, 0xD6, 0xD9, 0x00, 0xFD, 0x01, 0xAD, 0xFE, 0xCE, 0xDC, 0xD9, 0xE6, 0xD9, 0x00, 0xDD, 0xE7, 0x00, 0xD5, 0x00, 0xE8, 0xDD, 0xD7, 0xDF, 0xD9, 0xE8, 0x00, 0xDC, 0xD9, 0xE6, 0xD9, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xED, 0xE3, 0xE9, 0xAD, 0xFF, 0xC3, 0xE8, 0x00, 0xD5, 0xE4, 0xE4, 0xD9, 0xD5, 0xE6, 0xE7, 0x00, 0xE8, 0xE3, 0x00, 0xD6, 0xD9, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xE9, 0xE7, 0xD9, 0x00, 0xD5, 0xE8, 0x00, 0xE8, 0xDC, 0xD9, 0xFE, 0xC6, 0xC3, 0xC6, 0xD3, 0xBD, 0xC9, 0xD0, 0xBF, 0x00, 0xBD, 0xC3, 0xCE, 0xD3, 0x00, 0xE4, 0xE3, 0xE6, 0xE8, 0xAD, 0xFB, 0xD1, 0xDC, 0xED, 0x00, 0xE2, 0xE3, 0xE8, 0x00, 0xDB, 0xDD, 0xEA, 0xD9, 0x00, 0xDD, 0xE8, 0x00, 0xD5, 0x00, 0xE8, 0xE6, 0xED, 0x00, 0xD5, 0xE2, 0xD8, 0x00, 0xE7, 0xD9, 0xD9, 0x00, 0xEB, 0xDC, 0xD5, 0xE8, 0xFE, 0xDD, 0xE8, 0x00, 0xDD, 0xE7, 0x00, 0xD5, 0xD6, 0xE3, 0xE9, 0xE8, 0xAC, 0xFF, 0xCE, 0xDC, 0xD5, 0xE2, 0xDF, 0x00, 0xED, 0xE3, 0xE9, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xE9, 0xE7, 0xDD, 0xE2, 0xDB, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xC7, 0xD3, 0xCD, 0xCE, 0xBF, 0xCC, 0xD3, 0xFE, 0xC1, 0xC3, 0xC0, 0xCE, 0x00, 0xCD, 0xED, 0xE7, 0xE8, 0xD9, 0xE1, 0xAD, 0xFF, 0xC9, 0xDC, 0xB8, 0x00, 0xC3, 0xB4, 0xE1, 0x00, 0xE7, 0xE3, 0xE6, 0xE6, 0xED, 0xB8, 0x00, 0xFD, 0x01, 0xAD, 0xFE, 0xD3, 0xE3, 0xE9, 0xE6, 0x00, 0xBC, 0xBB, 0xC1, 0xB4, 0xE7, 0x00, 0xC5, 0xBF, 0xD3, 0x00, 0xC3, 0xCE, 0xBF, 0xC7, 0xCD, 0x00, 0xCA, 0xC9, 0xBD, 0xC5, 0xBF, 0xCE, 0x00, 0xDD, 0xE7, 0x00, 0xDA, 0xE9, 0xE0, 0xE0, 0xAD, 0xFB, 0xCA, 0xE0, 0xD9, 0xD5, 0xE7, 0xD9, 0x00, 0xE7, 0xE8, 0xE3, 0xE6, 0xD9, 0x00, 0xE7, 0xE3, 0xE1, 0xD9, 0xE8, 0xDC, 0xDD, 0xE2, 0xDB, 0x00, 0xE3, 0xE2, 0x00, 0xED, 0xE3, 0xE9, 0xE6, 0x00, 0xCA, 0xBD, 0xB8, 0xFE, 0xE8, 0xDC, 0xD9, 0xE2, 0x00, 0xD7, 0xE3, 0xE1, 0xD9, 0x00, 0xD6, 0xD5, 0xD7, 0xDF, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xE8, 0xDC, 0xDD, 0xE7, 0xAD, 0xFF, 0xB8, 0x27, 0x04, 0x00, 0x08, 0x6A, 0x5A, 0x2B, 0x3A, 0x01, 0xBB, 0x01, 0x8B, 0x04, 0x00, 0x08, 0x2B, 0xAD, 0x01, 0xBB, 0x01, 0x8B, 0x04, 0x00, 0x08, 0x47, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x01, 0x00, 0xBB, 0x01, 0x8B, 0x04, 0x00, 0x08, 0xBD, 0x94, 0x04, 0x00, 0x08, 0x66, 0x6D, 0x46, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x00, 0x00, 0xBB, 0x01, 0x82, 0x04, 0x00, 0x08, 0x1A, 0x00, 0x80, 0x73, 0x01, 0x1A, 0x01, 0x80, 0x01, 0x00, 0x09, 0x00, 0x29, 0xD5, 0x08, 0x29, 0x3A, 0x01, 0xBD, 0xED, 0x04, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xBD, 0x6B, 0x05, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xBD, 0x42, 0x05, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xC7, 0xD9, 0xE6, 0xD7, 0xDD, 0x00, 0xD8, 0xB4, 0xE9, 0xE8, 0xDD, 0xE0, 0xDD, 0xE7, 0xD9, 0xE6, 0x00, 0xE0, 0xD9, 0x00, 0xE7, 0xED, 0xE7, 0xE8, 0x1A, 0xE1, 0xD9, 0xFE, 0xBD, 0xBB, 0xBE, 0xBF, 0xBB, 0xCF, 0x00, 0xC7, 0xD3, 0xCD, 0xCE, 0xAD, 0xFB, 0xD0, 0xE3, 0xE9, 0xE7, 0x00, 0xD8, 0xD9, 0xEA, 0xD9, 0xEE, 0x00, 0x1C, 0xE8, 0xE6, 0xD9, 0x00, 0xFD, 0x01, 0xAD, 0xFE, 0xC3, 0xE0, 0x00, 0xED, 0x00, 0xD5, 0x00, 0xE9, 0xE2, 0x00, 0xE8, 0xDD, 0xD7, 0xDF, 0xD9, 0xE8, 0x00, 0xE4, 0xE3, 0xE9, 0xE6, 0x00, 0xEA, 0xE3, 0xE9, 0xE7, 0xAD, 0xFF, 0xC3, 0xE0, 0x00, 0xE4, 0xD9, 0xE9, 0xE8, 0x00, 0x1C, 0xE8, 0xE6, 0xD9, 0x00, 0xE9, 0xE8, 0xDD, 0xE0, 0xDD, 0xE7, 0x1B, 0x00, 0xD5, 0xE9, 0x00, 0xE4, 0xE3, 0xE6, 0xE8, 0x00, 0xD8, 0xD9, 0xFE, 0xC8, 0xBF, 0xC8, 0xCF, 0xBD, 0xCC, 0xC3, 0xCB, 0xCF, 0xBF, 0xAD, 0xFB, 0xBF, 0xE7, 0xE7, 0xD5, 0xED, 0xD9, 0xEE, 0xAE, 0xE0, 0xD9, 0x00, 0xE4, 0xE3, 0xE9, 0xE6, 0x00, 0xEA, 0xE3, 0xDD, 0xE6, 0x00, 0xD8, 0xD9, 0x00, 0xE5, 0xE9, 0xE3, 0xDD, 0x00, 0xFE, 0xDD, 0xE0, 0x00, 0xE7, 0xB4, 0xD5, 0xDB, 0xDD, 0xE8, 0xAD, 0xFF, 0xC7, 0xD9, 0xE6, 0xD7, 0xDD, 0x00, 0xD8, 0xB4, 0xE9, 0xE8, 0xDD, 0xE0, 0xDD, 0xE7, 0xD9, 0xE6, 0x00, 0xE0, 0xD9, 0x00, 0xE7, 0xED, 0xE7, 0xE8, 0x1A, 0xE1, 0xD9, 0xFE, 0xBD, 0xBB, 0xBE, 0xBF, 0xBB, 0xCF, 0x00, 0xC7, 0xD3, 0xCD, 0xCE, 0xAD, 0xFF, 0xC9, 0xDC, 0xB8, 0x00, 0xDE, 0xD9, 0x00, 0xE6, 0xD9, 0xDB, 0xE6, 0xD9, 0xE8, 0xE8, 0xD9, 0x00, 0xFD, 0x01, 0xAD, 0x00, 0xC6, 0xD5, 0x00, 0xCA, 0xC9, 0xBD, 0xC2, 0xBF, 0xFE, 0xC9, 0xBC, 0xC4, 0xAD, 0x00, 0xCC, 0xBB, 0xCC, 0xBF, 0xCD, 0x00, 0xD8, 0xE9, 0x00, 0xCD, 0xBB, 0xBD, 0x00, 0xD9, 0xE7, 0xE8, 0x00, 0xE4, 0xE0, 0xD9, 0xDD, 0xE2, 0xD9, 0xAD, 0xFB, 0xC0, 0xD5, 0xDD, 0xE8, 0xD9, 0xE7, 0x00, 0xE0, 0xD9, 0x00, 0xE8, 0xE6, 0xDD, 0x00, 0xD8, 0xD5, 0xE2, 0xE7, 0x00, 0xEA, 0xE3, 0xE8, 0xE6, 0xD9, 0x00, 0xCD, 0xBB, 0xBD, 0x00, 0xD9, 0xE8, 0xFE, 0xE6, 0xD9, 0xEA, 0xD9, 0xE2, 0xD9, 0xEE, 0x00, 0xE4, 0xE0, 0xE9, 0xE7, 0x00, 0xE8, 0xD5, 0xE6, 0xD8, 0xAD, 0xFF, 0xB8, 0xD9, 0x05, 0x00, 0x08, 0x6A, 0x5A, 0x2B, 0x3A, 0x01, 0xBB, 0x01, 0x3D, 0x06, 0x00, 0x08, 0x2B, 0xAD, 0x01, 0xBB, 0x01, 0x3D, 0x06, 0x00, 0x08, 0x47, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x01, 0x00, 0xBB, 0x01, 0x3D, 0x06, 0x00, 0x08, 0xBD, 0x46, 0x06, 0x00, 0x08, 0x66, 0x6D, 0x46, 0x73, 0x01, 0x01, 0x00, 0x21, 0x0D, 0x80, 0x00, 0x00, 0xBB, 0x01, 0x34, 0x06, 0x00, 0x08, 0x1A, 0x00, 0x80, 0x73, 0x01, 0x1A, 0x01, 0x80, 0x01, 0x00, 0x09, 0x00, 0x29, 0xD5, 0x08, 0x29, 0x3A, 0x01, 0xBD, 0xA9, 0x06, 0x00, 0x08, 0x66, 0x6D, 0x6C, 0x02, 0xBD, 0x3A, 0x07, 0x00, 0x08, 0x66, 0x6D, 0x00};
*/
// CRC16 checksum
void inject_mystery()
{
    flash_read(memory_section_array[4], &global_memory_buffer[0], 0x1000);
    for (int i = 0; i < 0x14E; i++)
    {
        global_memory_buffer[INTER_WONDER_CARD_OFFSET_EMER + i] = wonder_card[i];
    }
    mystery_gift_script script;
    script.build_script();
    for (int i = 0; i < 0x3EC; i++){
        global_memory_buffer[EVENT_SCRIPT_DATA_OFFSET_EMER + i] = script.get_script_value_at(i);
    }
    update_memory_buffer_checksum();
    flash_write(memory_section_array[4], &global_memory_buffer[0], 0x1000);
}

/*
000168:                         The main function
    push  {lr}                      save the load register to the stack
    ldr   r3, [pc, <000188>]        set r3 to variable to 0x020375E8 (the pokemon offset, variable 0x8008's pointer)
    ldr   r3, [r3, #0]              set r3 to the value in memory r3 points to
    add   r0, pc, #28               set r0 to a pointer 28 bytes ahead, which is the start of the Pokemon struct
    add   r0, r0, r3                add r3 to r0, giving it the correct offset for the current index
    ldr   r1, [pc, <000180>]        set r1 to 0x0806B491, which is the location of "SendMonToPC" plus one, since it is thumb code
    mov   r2, r15                   move r15 (the program counter) to r2
    add   r2, r2, #7                add 7 to r2 to compensate for the six following bytes, plus to tell the system to read as thumb code
    mov   r14, r2                   move r2 into r14 (the load register)
    bx    r1                        jump to the pointer stored in r1 (SendMonToPC)
00017A:                         The second part of the function
    ldr   r2, [pc, <000184>]        load 0x020375E4 (variable 0x8006's pointer) into r2
    str   r0, [r2, #0]              put the value of r0 into the memory location pointed at by r2, plus 0
    pop   {r0}                      remove r0 from the stack and put it into r0
    bx    r0                        jump to r0 (return to where the function was called)
000180:
    .word 0x0806B491                the location of "SendMonToPC", plus one (so it is interpreted as thumb code)
000184: 
    .word 0x020375E4                the location of variable "0x8006" (the return value)
000188:
    .word 0x020375E8                the location of variable "0x8008" (the pokemon offset)
*/