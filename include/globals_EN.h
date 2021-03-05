//
// file: globals.h
//
// This	file is	#included in all objects automatically by the driver.
// (See	config file	of driver)

// Directories

#define	COMMAND_DIR				"/cmds/"
#define	CONFIG_DIR				"/adm/etc/"
#define	DATA_DIR				"/data/"
#define	HELP_DIR				"/doc/"
#define	LOG_DIR					"/log/"

#include <path.h>

// Daemons
#define	ALIAS_D					"/adm/daemons/aliasd"
#define	BAN_D					"/adm/daemons/band"
#define	BN_D					"/adm/daemons/bnd"
#define	BR_D					"/adm/daemons/brd"
#define	CHANNEL_D				"/adm/daemons/channeld"
#define	CHAR_D					"/adm/daemons/chard"
#define	CHINESE_D				"/adm/daemons/chinesed"
#define	COMBAT_D				"/adm/daemons/combatd"
#define	COMMAND_D				"/adm/daemons/cmd_d"
#define	EMOTE_D					"/adm/daemons/emoted"
#define	ENCODE_D				"/adm/daemons/encoded"
#define	EVENT_D					"/adm/daemons/eventd"
#define	FINGER_D				"/adm/daemons/fingerd"
#define	INQUIRY_D				"/adm/daemons/inquiryd"
#define	ITEM_D					"/adm/daemons/itemd"
#define	LOGIN_D					"/adm/daemons/logind"
#define MF_D					"/adm/daemons/mfd"
#define	NATURE_D				"/adm/daemons/natured"
#define	PIG_D					"/adm/daemons/pigd"
#define	PROFILE_D				"/adm/daemons/profiled"
#define QUESTS_D				"/adm/daemons/questd"
#define	RANK_D					"/adm/daemons/rankd"
#define	SECURITY_D				"/adm/daemons/securityd"
#define	STATUS_D				"/adm/daemons/statusd"
#define	TASK_D					"/adm/daemons/taskd"
#define	UPDATE_D				"/adm/daemons/updated"
#define	VIRTUAL_D				"/adm/daemons/virtuald"
#define	VOTE_D					"/adm/daemons/voted"
#define	WHO_D					"/adm/daemons/whod"
#define COOR_D					"/adm/daemons/coord"
#define NETBAR_D  				"/adm/daemons/netbard"
#define MONEY_D  				"/adm/daemons/moneyd"
#define MAGIC_D					"/adm/daemons/magicd"
#define PK_D					"/adm/daemons/pkd"
#define VILLAGE_D				"/adm/daemons/villaged"
#define REWARD_D				"/adm/daemons/rewardd"
#define SPAWN_D					"/adm/daemons/spawnd"

//added by suu for quest npc
#define QUESTNPC_D				"/adm/daemons/questnpcd"

//added by silencer for advanced NPC control
#define SMART_D					"/adm/daemons/smartd"

//added by annie for buff/debuff control
#define ANNIE_D					"/adm/daemons/annied"

//added by annie. 
//0:Local 1:Develop 2:Test 3:Live
#define SERV					3
#define LOCAL					0
#define DEV						1
#define TEST					2
#define LIVE					3

//	added by Silencer for compability between Encypted/Non_Encrypted site
//	Encrpted site should define this to get the those write_file2() working.
#define ENCRYPTED_WRITE				1
//	#define NONENCRYPTED_WRITE				1

// added by	Tie	for	questing
#define	QUEST_D(x)				("/quest/qlist"	+ x)
#define	CLASS_D(x)				("/daemon/class/" + x)
#define	SKILL_D(x)				("/daemon/skill/" + x)
#define	CONDITION_D(x)			("/daemon/condition/" +	x)


// Clonable/Non-inheritable	Standard Objects

#define	COIN_OB					"/obj/money/coin"
#define	CORPSE_OB				"/obj/item/corpse"
#define	LOGIN_OB				"/obj/login"
#define	MASTER_OB				"/adm/obj/master"
#define	MAILBOX_OB				"/obj/item/mailbox"
#define	SILVER_OB				"/obj/money/silver"
#define	GOLD_OB					"/obj/money/gold"
#define	THCASH_OB				"/obj/money/thousand-cash"
#define	TECASH_OB				"/obj/money/tenthousand-cash"
#define	SIMUL_EFUN_OB			"/adm/obj/simul_efun"
#define	USER_OB					"/obj/user"
#define	VOID_OB					"/obj/void"


// Inheritable Standard	Objects
#define	BULLETIN_BOARD				"/std/bboard"

#define	CHARACTER				"/std/char"
#define	NPC						"/std/char/npc"
#define	QUESTNPC				"/std/char/questnpc"
#define	SMART_NPC				"/std/char/smart_npc"
#define	CRAZY_NPC				"/std/char/crazynpc"
#define	WALL					"/std/char/wall"


#define MAZE_NPC				"/d/maze/npc/maze_npc"
#define NPC_ANN					"/std/char/npc_ann"
#define NPC_041					"/std/char/npc_041"
#define NPC_ADV					"/std/char/npc_adv"
#define NPC_MID					"/std/char/npc_mid"
#define NPC_BAS					"/std/char/npc_bas"

#define	COMBINED_ITEM			"/std/item/combined"
#define	EQUIP					"/std/equip"
#define	WEAR					"/std/wear"
#define	WIELD					"/std/wield"
#define	ITEM					"/std/item"

#define	POWDER					"/std/medicine/powder"
#define	LIQUID					"/std/liquid"
#define	MONEY					"/std/money"
#define MEDICINE				"/std/medicine/medicine"

#define TUTOR					"/obj/book/moon/tutor"
#define BOOKS					"/obj/book/"
#define	ROOM					"/std/room"
#define	PIGROOM					"/std/room/pigroom"
#define DOOR_ROOM				"/std/room/door_room"
#define NEWBIE_HELP_ROOM		"/std/room/startroom"
#define XROOM 					"/std/room/xroom" 

#define	SKILL					"/std/skill"
#define	SSERVER					"/std/sserver"
#define VRM_SERVER              "/std/room/vrm_server"
#define VRM_SERVER2             "/std/room/vrm_server2"
#define VRM_SERVER3             "/std/room/vrm_server3"


// User	IDs
#define	ROOT_UID				"Root"
#define	BACKBONE_UID			"Backbone"

// Features
#define	F_ACTION				"/feature/action.c"
#define	F_ALIAS					"/feature/alias.c"
#define	F_APPRENTICE			"/feature/apprentice.c"
#define	F_ATTACK				"/feature/attack.c"
#define	F_ATTRIBUTE				"/feature/attribute.c"
#define	F_AUTOLOAD				"/feature/autoload.c"
#define	F_BANKOWNER				"/feature/bankowner.c"
#define	F_CLEAN_UP				"/feature/clean_up.c"
#define	F_COMMAND				"/feature/command.c"
#define	F_CONDITION				"/feature/condition.c"
#define	F_DAMAGE				"/feature/damage.c"
#define	F_DBASE					"/feature/dbase.c"
#define	F_EDIT					"/feature/edit.c"
#define	F_EQUIP					"/feature/equip.c"
#define	F_FINANCE				"/feature/finance.c"
#define	F_FOOD					"/feature/food.c"
#define	F_LEADER				"/std/char/oleader.c"
#define	F_LIQUID				"/feature/liquid.c"
#define	F_MESSAGE				"/feature/message.c"
#define	F_MORE					"/feature/more.c"
#define	F_MOVE					"/feature/move.c"
#define	F_NAME					"/feature/name.c"
#define	F_PAWN					"/feature/pawn.c"
#define	F_PAWNOWNER				"/feature/pawnowner.c"
#define	F_QUEST					"/feature/quest.c"
#define	F_SAVE					"/feature/save.c"
#define	F_SKILL					"/feature/skill.c"
#define	F_TEAM					"/feature/team.c"
#define	F_TREEMAP				"/feature/treemap.c"
#define	F_VENDOR				"/feature/vendor.c"
#define F_FLOWERSELLER				"/feature/flowerseller.c"
#define	F_MASTER				"/std/char/master.c"
#define F_VO					"/feature/vo.c"

#define	F_ANNIE					"/feature/annie.c"
#define F_LEVEL					"/feature/exp_level.c"
#define F_ABILITY				"/feature/ability.c"

#define	SAVE_EXTENSION			".o"
// Profiling switches
//
// If you changed any of these defines,	you'll need	reboot to make it 
// in effect.
#undef PROFILE_COMMANDS

