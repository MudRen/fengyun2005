#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 63
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "ffj"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1538479118"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "随便玩十号的家");
set("long", @LONG
这次真的只是玩玩，想不出来描述了，太多房子了
这次真的只是玩玩，想不出来描述了，太多房子了
这次真的只是玩玩，想不出来描述了，太多房子了
这次真的只是玩玩，想不出来描述了，太多房子了

LONG
);
        set("exits", ([
"out" : "/p/residence/sword9.c",
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
