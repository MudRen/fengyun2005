#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 5
#define CONSTRUCT_TREE 1
#define BASIC_TAX 2240
#define BASIC_SCORE_TAX 500

#define TOTAL_GOLD 2400
#define TOTAL_SCORE 820

#define OWNER "mla"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1535373253"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "凯旋宫");
set("long", @LONG
漫天瑞雪，纷纷扬扬；寒风怒吼，落木萧萧；漫漫苍天，茫茫原野——大地在倾刻间披上了银妆，以往清澈见底的河水、明朗的天空都变成了略带沉重的铅色，银色的世界洗净了铅华，沉淀了四季的尘埃。

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
