#ifndef ENG_GB_ROM_VALUES_H
#define ENG_GB_ROM_VALUES_H

// These are redefined because C++ doesn't like compiling TONC
#define JPN_ID 1
#define ENG_ID 2
#define FRE_ID 3
#define ITA_ID 4
#define GER_ID 5
#define SPA_ID 7
#define KOR_ID 8

#define GREEN_ID 0
#define RED_ID 1
#define BLUE_ID 2
#define YELLOW_ID 3
#define GOLD_ID 4
#define SILVER_ID 5
#define CRYSTAL_ID 6

#define METHOD_NEWLINE 0
#define METHOD_MEW 1
#define METHOD_GEN2 2

#include "gb_rom_values/base_gb_rom_struct.h"

const struct GB_ROM ENG_RED_BLUE = {
    .language = ENG_ID,
    .version = RED_ID,
    .generation = 1,
    .method = METHOD_NEWLINE,
    .payload_size = 637,
    .box_data_size = 0x462,

    .print_string_start = 0xC456,
    .stack_overwrite_location = 0xDFDD,
    .short_pkmn_name = 0xE3,
    .pointer_pkmn_name = 0xFC,

    .enter_vector_location = 0xC5D6,

    .clearScreen = 0x190F,
    .CableClub_TextBoxBorder = 0x5AB3,
    .placeString = 0x1955,
    .Serial_ExchangeBytes = 0x216F,
    ._RemovePokemon = 0x7B68,
    .SaveSAVtoSRAM1 = 0x1C77E2,
    .SaveSAVtoSRAM2 = 0x1C780F,
    .Bankswitch = 0x35D6,
    .SoftReset = 0x1F49,
    .garbageDataLocation = 0x0316,

    .wRemoveMonFromBox = 0xCF95,
    .wBoxCount = 0xDA80,
    .wWhichPokemon = 0xCF92,
    .hSerialConnectionStatus = 0xFFAA,
    .wBoxDataStart = 0xDA80,
    .wBoxDataEnd = 0xDEE2,

    .transferWaitString = 0xC67A,
    .pkmnTransferArray = 0xC651,
    .arrayCounter = 0xC650,
    .transferString = {// TRANSFERRING..\n
                       //  PLEASE WAIT!
                       0x93, 0x91, 0x80, 0x8D, 0x92, 0x85, 0x84, 0x91, 0x91, 0x88, 0x8D, 0x86, 0xF2, 0xF2, 0x4E,
                       0x7F, 0x8F, 0x8B, 0x84, 0x80, 0x92, 0x84, 0x7F, 0x96, 0x80, 0x88, 0x93, 0xE7, 0x7F, 0x50},
    .custom_name = {0x85, 0x84, 0x8D, 0x8D, 0x84, 0x8B, 0x50, 0x50, 0x50, 0x50, 0x50},

    .transferStringLocation = 0xC443,
    .textBorderUppLeft = 0xC42E,
    .textBorderWidth = 3,
    .textBorderHeight = 14,
};
const struct GB_ROM ENG_YELLOW = {
    .language = ENG_ID,
    .version = YELLOW_ID,
    .generation = 1,
    .method = METHOD_MEW,
    .payload_size = 637,
    .box_data_size = 0x462,

    .print_string_start = 0xC456,
    .stack_overwrite_location = 0xDFDD,
    .short_pkmn_name = 0x15,
    .pointer_pkmn_name = 0xE3,

    .clearScreen = 0x16DD,
    .CableClub_TextBoxBorder = 0x5B67,
    .placeString = 0x1723,
    .Serial_ExchangeBytes = 0x1FCB,
    ._RemovePokemon = 0x7A0F,
    .SaveSAVtoSRAM1 = 0x1C1B32,
    .Bankswitch = 0x3E84,
    .SoftReset = 0x1D05,
    .garbageDataLocation = 0x0161,
    .wRemoveMonFromBox = 0xCF94,
    .wBoxCount = 0xDA7F,
    .wWhichPokemon = 0xCF91,
    .hSerialConnectionStatus = 0xFFAA,

    .wBoxDataStart = 0xDA7F,
    .wBoxDataEnd = 0xDEE1,

    .transferWaitString = 0xC67A,
    .pkmnTransferArray = 0xC651,
    .arrayCounter = 0xC650,
    .transferString = {// TRANSFERRING..\n
                       //  PLEASE WAIT!
                       0x93, 0x91, 0x80, 0x8D, 0x92, 0x85, 0x84, 0x91, 0x91, 0x88, 0x8D, 0x86, 0xF2, 0xF2, 0x4E,
                       0x7F, 0x8F, 0x8B, 0x84, 0x80, 0x92, 0x84, 0x7F, 0x96, 0x80, 0x88, 0x93, 0xE7, 0x7F, 0x50},
    .custom_name = {0x85, 0x84, 0x8D, 0x8D, 0x84, 0x8B, 0x50, 0x50, 0x50, 0x50, 0x50},

    .transferStringLocation = 0xC443,
    .textBorderUppLeft = 0xC42E,
    .textBorderWidth = 3,
    .textBorderHeight = 14,
};
const struct GB_ROM ENG_GOLD = {
    .language = ENG_ID,
    .version = GOLD_ID,
    .generation = 2,
    .method = METHOD_GEN2,
    .payload_size = 672,
    .box_data_size = 0x44E,

    .print_string_start = 0xC442,
    .stack_overwrite_location = 0xDFCB, // Found by seeing where 772C is stored in the stack, 772C is the code that calls PlaceString
    .short_pkmn_name = 0x4E,

    .jump_vector_location = 0xC7B4,
    .enter_vector_location = 0xC5D6,

    .clearScreen = 0x000EE2,
    .CableClub_TextBoxBorder = 0x0A4D88, // LinkTextboxAtHL
    .placeString = 0x000F74,
    .Serial_ExchangeBytes = 0x0710,
    ._RemovePokemon = 0x03603F, // RemoveMonFromPartyOrBox
    .OpenSRAM = 0x0030E1,
    .SaveBox = 0x054DF6,
    .SoftReset = 0x05B0,
    .garbageDataLocation = 0x0654,

    .wRemoveMonFromBox = 0x01D008, // wPokemonWithdrawDepositParameter
    .wBoxCount = 0x01AD6C,         // sBoxCount
    .wWhichPokemon = 0x01D005,     // wCurPartyMon
    .hSerialConnectionStatus = 0xFFCD,
    .wBoxDataStart = 0xAD6C, // sBoxStart
    .wBoxDataEnd = 0xB1BA,   // sBoxEnd

    .transferWaitString = 0xC67A,
    .pkmnTransferArray = 0xC651,
    .arrayCounter = 0xC650,
    .transferString = {// TRANSFERRING..\n
                       //  PLEASE WAIT!
                       0x93, 0x91, 0x80, 0x8D, 0x92, 0x85, 0x84, 0x91, 0x91, 0x88, 0x8D, 0x86, 0xF2, 0xF2, 0x4E,
                       0x7F, 0x8F, 0x8B, 0x84, 0x80, 0x92, 0x84, 0x7F, 0x96, 0x80, 0x88, 0x93, 0xE7, 0x7F, 0x50},
    .custom_name = {0x85, 0x84, 0x8D, 0x8D, 0x84, 0x8B, 0x50, 0x50, 0x50, 0x50, 0x50},

    .transferStringLocation = 0xC443,
    .textBorderUppLeft = 0xC42E,
    .textBorderWidth = 3,
    .textBorderHeight = 14,
};
const struct GB_ROM ENG_SILVER = {
    .language = ENG_ID,
    .version = SILVER_ID,
    .generation = 2,
    .method = METHOD_GEN2,
    .payload_size = 672,
    .box_data_size = 0x44E,

    .print_string_start = 0xC442,
    .stack_overwrite_location = 0xDFCB, // Found by seeing where 772C is stored in the stack, 772C is the code that calls PlaceString
    .short_pkmn_name = 0x4E,

    .jump_vector_location = 0xC7B4,
    .enter_vector_location = 0xC5D6,

    .clearScreen = 0x000EE2,
    .CableClub_TextBoxBorder = 0x0A4D88, // LinkTextboxAtHL
    .placeString = 0x000F74,
    .Serial_ExchangeBytes = 0x0710,
    ._RemovePokemon = 0x03603D, // RemoveMonFromPartyOrBox
    .OpenSRAM = 0x0030E1,
    .SaveBox = 0x054DF6,
    .SoftReset = 0x05B0,
    .garbageDataLocation = 0x0654,

    .wRemoveMonFromBox = 0x01D008, // wPokemonWithdrawDepositParameter
    .wBoxCount = 0x01AD6C,         // sBoxCount
    .wWhichPokemon = 0x01D005,     // wCurPartyMon
    .hSerialConnectionStatus = 0xFFCD,
    .wBoxDataStart = 0xAD6C, // sBoxStart
    .wBoxDataEnd = 0xB1BA,   // sBoxEnd

    .transferWaitString = 0xC67A,
    .pkmnTransferArray = 0xC651,
    .arrayCounter = 0xC650,
    .transferString = {// TRANSFERRING..\n
                       //  PLEASE WAIT!
                       0x93, 0x91, 0x80, 0x8D, 0x92, 0x85, 0x84, 0x91, 0x91, 0x88, 0x8D, 0x86, 0xF2, 0xF2, 0x4E,
                       0x7F, 0x8F, 0x8B, 0x84, 0x80, 0x92, 0x84, 0x7F, 0x96, 0x80, 0x88, 0x93, 0xE7, 0x7F, 0x50},
    .custom_name = {0x85, 0x84, 0x8D, 0x8D, 0x84, 0x8B, 0x50, 0x50, 0x50, 0x50, 0x50},

    .transferStringLocation = 0xC443,
    .textBorderUppLeft = 0xC42E,
    .textBorderWidth = 3,
    .textBorderHeight = 14,
};
const struct GB_ROM ENG_CRYSTAL = {
    .language = ENG_ID,
    .version = CRYSTAL_ID,
    .generation = 2,
    .method = METHOD_GEN2,
    .payload_size = 672,
    .box_data_size = 0x44E,

    .print_string_start = 0xC544,
    .stack_overwrite_location = 0xE0BB, // Found by seeing where 7622 is stored in the stack, 7622 is the code that calls PlaceString (PlaceTradePartnerNamesAndParty)
    .short_pkmn_name = 0x4E,

    .jump_vector_location = 0xD33C,
    .enter_vector_location = 0xC6D6, // wOTPatchLists, plus preamble

    .clearScreen = 0x000FDB,
    .CableClub_TextBoxBorder = 0x0A4EEF, // LinkTextboxAtHL
    .placeString = 0x001078,
    .Serial_ExchangeBytes = 0x075F,
    ._RemovePokemon = 0x036039, // RemoveMonFromPartyOrBox
    .OpenSRAM = 0x002FCB,
    .SaveBox = 0x054E0C,
    .SoftReset = 0x0150, // Reset
    .garbageDataLocation = 0x0770,

    .wRemoveMonFromBox = 0x01D10B, // wPokemonWithdrawDepositParameter
    .wBoxCount = 0x01AD10,         // sBoxCount
    .wWhichPokemon = 0x01D109,     // wCurPartyMon
    .hSerialConnectionStatus = 0xFFCB,
    .wBoxDataStart = 0x01AD10, // sBox
    .wBoxDataEnd = 0x01B15E,   // sBoxEnd

    .transferWaitString = 0xC77A,
    .pkmnTransferArray = 0xC751,
    .arrayCounter = 0xC750,
    .transferString = {// TRANSFERRING..\n
                       //  PLEASE WAIT!
                       0x93, 0x91, 0x80, 0x8D, 0x92, 0x85, 0x84, 0x91, 0x91, 0x88, 0x8D, 0x86, 0xF2, 0xF2, 0x4E,
                       0x7F, 0x8F, 0x8B, 0x84, 0x80, 0x92, 0x84, 0x7F, 0x96, 0x80, 0x88, 0x93, 0xE7, 0x7F, 0x50},
    .custom_name = {0x85, 0x84, 0x8D, 0x8D, 0x84, 0x8B, 0x50, 0x50, 0x50, 0x50, 0x50},

    .transferStringLocation = 0xC543,
    .textBorderUppLeft = 0xC52E,
    .textBorderWidth = 3,
    .textBorderHeight = 14,
};

#endif