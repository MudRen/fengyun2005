#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "poemecho"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1508152945"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "风云阁");
set("long", @LONG

风云阁的主人就是当年天下大名鼎鼎的小李飞刀。虽然李探花已经隐退多时，
但是还有客人慕名来到此阁，以求一面之缘。阁中大红波斯地毯铺地，富丽堂
皇。朱红的大门两侧各挂一幅石刻的对联儿：

                        一门七进士
                        父子三探花



LONG
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
