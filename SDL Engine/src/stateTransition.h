#pragma once

/*

					NOTE

	Below are to be used to help transition
	from one state to the other. Keeping the
	flow of the game constant throught all
	states in all files.

*/

//Anywhere with the option to quite the game
#define QUIT_GAME -1

// !! State 0 is reserved for NULL usage !! //

//Loading screen
#define LOADING_SCREEN 999

//Home screen (pre-main menu)
#define HM_SPLASHSCREEN 1
#define HM_HOME_SCREEN 2

//Main menu
#define MM_MAIN_MENU 10
#define MM_CONTINUE_GAME 11
#define MM_NEW_GAME 12
#define MM_LOAD_MENU 13
#define MM_SETTINGS_MENU 14
#define MM_QUIT_GAME 15

//Load-Save menu
#define LSM_LOAD_SAVE_MENU 20
#define LSM_SAVE_SLOT_1 21
#define LSM_SAVE_SLOT_2 22
#define LSM_SAVE_SLOT_3 23
#define LSM_SAVE_SLOT_4 24
#define LSM_SAVE_SLOT_5 25
#define LSM_SAVE_SLOT_6 26
#define LSM_SAVE_SLOT_7 27
#define LSM_SAVE_SLOT_8 28
#define LSM_PREV_PAGE 29
#define LSM_RETURN_BUTTON 30
#define LSM_NEXT_PAGE 31

//Settings menu
#define SM_SETTINGS_MENU 40
#define SM_RENDER_SOFTWARE 41
#define SM_RENDER_HARDWARE 42
#define SM_RENDER_V_SYNC 43
#define SM_FPS_LIMIT_30 44
#define SM_FPS_LIMIT_60 45
#define SM_FPS_LIMIT_120 46
#define SM_FPS_LIMIT_UNLIMITED 47
#define SM_SHOW_FPS_ON  48
#define SM_SHOW_FPS_OFF 49
#define SM_SCREEN_FULLSCREEN 50
#define SM_SCREEN_WINDOWED 51
#define SM_RESOLUTION_480 52
#define SM_RESOLUTION_600 53
#define SM_RESOLUTION_720 54
#define SM_RESOLUTION_900 55
#define SM_RESOLUTION_1080 56
#define SM_RESOLUTION_1440 57
#define SM_RESOLUTION_2160 58
#define SM_RETURN_BUTTON 59

//In-game menu
#define IGM_IN_GAME_MENU 60
#define IGM_RESUME_GAME 61
#define IGM_SAVE_MENU 62
#define IGM_LOAD_MENU 63
#define IGM_SETTINGS_MENU 64
#define IGM_MAIN_MENU 65
#define IGM_QUIT_GAME 66

//Character Select menu
#define CSM_CHARACTER_SELECT_MENU 70
#define CSM_FIGHTER_1 71
#define CSM_FIGHTER_2 72
#define CSM_FIGHTER_3 73
#define CSM_FIGHTER_4 74
#define CSM_FIGHTER_5 75
#define CSM_FIGHTER_6 76
#define CSM_FIGHTER_7 77
#define CSM_FIGHTER_8 78
#define CSM_FIGHTER_9 79
#define CSM_FIGHTER_10 80
#define CSM_FIGHTER_11 81
#define CSM_FIGHTER_12 82
#define CSM_FIGHTER_13 83
#define CSM_FIGHTER_14 84
#define CSM_FIGHTER_15 85
#define CSM_FIGHTER_16 86
#define CSM_FIGHTER_17 87
#define CSM_FIGHTER_18 88
#define CSM_FIGHTER_19 89
#define CSM_FIGHTER_20 90
#define CSM_QUIT_TO_MAIN_MENU 91

//Stages
#define TEST_STAGE 100
#define STAGE_1 101
#define STAGE_2 102
#define STAGE_3 103
#define STAGE_4 104
#define STAGE_5 105
#define STAGE_6 106
#define STAGE_7 107
#define STAGE_8 108
#define STAGE_9 109
#define STAGE_10 110

//Fight over menu
#define FOM_FIGHT_OVER_MENU 120
#define FOM_REMATCH 121
#define FOM_CHANGE_CHARACTER 122
#define FOM_MAIN_MENU 123