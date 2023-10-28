#ifndef SCRIPT_ARRAY_H
#define SCRIPT_ARRAY_H

#include "script_obj.h"
#include "pokemon_party.h"


// Start!
#define SCRIPT_START 0
#define START_SIZE 1

// Dialouge
#define DIA_INDEX_OPEN 0
#define DIA_INDEX_E4_1 1
#define DIA_INDEX_E4_2 2
#define DIA_INDEX_MG 3
#define DIA_INDEX_START 4
#define DIA_INDEX_ERROR_1 5
#define DIA_INDEX_CONN_GOOD 6
#define DIA_INDEX_LINK_GOOD 7
#define DIA_INDEX_TRANS_GOOD 8 
#define DIA_INDEX_NEW_DEX 9
#define DIA_INDEX_NO_NEW_DEX 10
#define DIA_INDEX_SEND_FRIEND 11
#define DIA_INDEX_THANK 12

#define DIA_F_OPEN START_SIZE + DIA_INDEX_OPEN
#define DIA_F_E4_1 START_SIZE + DIA_INDEX_E4_1
#define DIA_F_E4_2 START_SIZE + DIA_INDEX_E4_2
#define DIA_F_MG START_SIZE + DIA_INDEX_MG
#define DIA_F_START START_SIZE + DIA_INDEX_START
#define DIA_F_ERROR_1 START_SIZE + DIA_INDEX_START
#define DIA_F_CONN_GOOD START_SIZE + DIA_INDEX_CONN_GOOD
#define DIA_F_LINK_GOOD START_SIZE + DIA_INDEX_LINK_GOOD
#define DIA_F_TRANS_GOOD START_SIZE + DIA_INDEX_TRANS_GOOD
#define DIA_F_NEW_DEX START_SIZE + DIA_INDEX_NEW_DEX
#define DIA_F_NO_NEW_DEX START_SIZE + DIA_INDEX_NO_NEW_DEX
#define DIA_F_SEND_FRIEND START_SIZE + DIA_INDEX_SEND_FRIEND
#define DIA_F_THANK START_SIZE + DIA_INDEX_THANK

#define DIA_SIZE 13
#define DIA_END DIA_SIZE + START_SIZE

// Commands
#define CMD_START_LINK DIA_END + 0
#define CMD_IMPORT_POKEMON DIA_END + 1
#define CMD_BACK_TO_MENU DIA_END + 2
#define CMD_SHOW_PROF DIA_END + 3
#define CMD_HIDE_PROF DIA_END + 4

#define CMD_SIZE 5
#define CMDS_END DIA_END + CMD_SIZE

// Conditionals
#define COND_ERROR_TIMEOUT_ONE CMDS_END + 0
#define COND_ERROR_DISCONNECT CMDS_END + 1
#define COND_ERROR_COM_ENDED CMDS_END + 2
#define COND_ERROR_TIMEOUT_TWO CMDS_END + 3
#define COND_ERROR_COLOSSEUM CMDS_END + 4
#define COND_BEAT_E4 CMDS_END + 5
#define COND_MG_ENABLED CMDS_END + 6

#define COND_SIZE 7
#define COND_END CMDS_END + COND_SIZE

// Ends

#define SCRIPT_SIZE COND_END

extern script_obj script[];

void populate_script();
void populate_dialouge();
void add_script_party_var(Pokemon_Party var);
bool run_conditional(int index);
std::string_view format_text(std::string_view text);

#endif