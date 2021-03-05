#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 160
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "field"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1574321449"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "无聊一");
set("long", @LONG
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间
这是无聊高月的房间

LONG
);
        set("exits", ([
"out" : "/p/residence/cloud4.c",
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
