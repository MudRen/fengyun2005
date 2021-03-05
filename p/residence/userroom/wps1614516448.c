#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 3
#define CONSTRUCT_TREE 1
#define BASIC_TAX 560
#define BASIC_SCORE_TAX 300

#define TOTAL_GOLD 600
#define TOTAL_SCORE 380

#define OWNER "wps"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1614516448"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "墨长生山庄");
set("long", @LONG
墨长生山庄是一座小小的山庄你问我为什么叫山庄因为它的主人是富贵山庄的弟子啊可是富贵好像不是很强啊摇判门到哪个门派呢慢慢熬吧

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
