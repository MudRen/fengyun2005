#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 120
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "hmt"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1512009990"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "失乐园");
set("long", @LONG
皑皑的白雪中，木屋暖色的灯光让人似乎看到了希望，软的垫子，清新的松木香。窗外，海浪托着浮冰，如风中的绸缎一般，一层又一层的涌向海岸线。
。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword3.c",
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
