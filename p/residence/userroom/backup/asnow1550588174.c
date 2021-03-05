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

#define OWNER "asnow"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1550588174"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "忘忧谷");
set("long", @LONG
结庐在人境，而无车马喧。问君何能尔，心远地自偏。
    采菊东篱下，悠然见南山。山气日夕佳，飞鸟相与还。
    此中有真意，欲辨已忘言。此中有真意，欲辨已忘言。

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
