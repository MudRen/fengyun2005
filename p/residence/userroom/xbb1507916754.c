#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "xbb"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1507916754"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "浮生半日");
set("long", @LONG
今朝有酒今朝醉，明日愁来明日愁。天生我材必有用，千金散尽还复来。
今朝有酒今朝醉，明日愁来明日愁。天生我材必有用，千金散尽还复来。因过竹院逢僧话，偷得浮生半日闲。

LONG
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
