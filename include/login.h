#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT		90

#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO			"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"

#define WIZLIST				"/adm/etc/wizlist"

#define START_ROOM			AREA_FY"church"
#define DEATH_ROOM			AREA_DEATH"yanluo"
#define DEATH_ROOM_NO_PEN		AREA_DEATH"wangsi"
#define REVIVE_ROOM			AREA_FY"church"
#define NEWBIE_ROOM			AREA_WELCOME"newbie1"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS			200

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			AREA_WIZ"courthouse"

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL 0

// This defines if the game takes new player at this moment
#define NEW_USER_LOCK 0
#endif
