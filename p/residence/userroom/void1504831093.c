#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 80
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "void"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1504831093"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "秋心");
set("long", @LONG

　　秋心如海复如潮，
　　但有秋魂不可招。
　　漠漠郁金香在臂，
　　亭亭古玉佩当腰。
　　气寒西北何人剑，
　　声满东南几处箫。
　　斗大明星烂无数，
　　长天一月坠林梢。


LONG
);
        set("exits", ([
"out" : "/p/residence/cloud2.c",
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
