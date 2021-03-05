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

#define OWNER "zyu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503291304"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "昨夜星辰");
set("long", @LONG

　　昨夜星辰昨夜风，
　　画楼西畔桂堂东。
　　身无彩凤双飞翼，
　　心有灵犀一点通。
　　隔座送钩春酒暖，
　　分曹射覆蜡灯红。
　　嗟余听鼓应官去，
　　走马兰台类转蓬。


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
