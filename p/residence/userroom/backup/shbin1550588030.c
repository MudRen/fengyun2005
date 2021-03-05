#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 1
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "shbin"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1550588030"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "飘渺峰");
set("long", @LONG
问世间、情为何物，直教生死相许？
    天南地北双飞客，老翅几回寒暑。
    欢乐趣，离别苦，就中更有痴儿女。
    君应有语，渺万里层云，千山暮雪，只影向谁去？

LONG
);
        set("exits", ([
"out" : "/p/residence/tower9.c",
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
