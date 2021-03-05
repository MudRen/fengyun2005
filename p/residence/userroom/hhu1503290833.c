#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "hhu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503290833"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "登高");
set("long", @LONG

　　风急天高猿啸哀，
　　渚清沙白鸟飞回。
　　无边落木萧萧下，
　　不尽长江滚滚来。
　　万里悲秋常作客，
　　百年多病独登台。
　　艰难苦恨繁霜鬓，
　　潦倒新停浊酒杯。 


LONG
);
        set("exits", ([
"out" : "/p/residence/cloud1.c",
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
