#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "heng"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1589142762"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "横刀立马");
set("long", @LONG
谁敢横刀立马唯我彭大将军天人三叹魔教无踪碎玉神罡长庚指鬼知道在哪里啊玩个游戏还这么难攻略在哪里有没有可玩性啊中年听雨客舟中天低江阔断雁叫西风而今听雨僧庐下鬓已星星也

LONG
);
        set("exits", ([
"out" : "/p/residence/smile9.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("timestamp2",TIMESTAMP2);
	set("free_space",FREE_SPACE);
	set("basic_tax",BASIC_TAX);
	set("basic_score_tax",BASIC_SCORE_TAX);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}
