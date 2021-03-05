#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "scene"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1505050889"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "淡云居");
set("long", @LONG
半肩风雨半肩柴，竹杖芒鞋破碧崖。刚出岭头三五步，浑身都被乱云埋。经行仿佛近诸天，月上山衔半缺圆。听得上方相对话，星辰莫阂五峰巅。

LONG
);
        set("exits", ([
"out" : "/p/residence/tower1.c",
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
