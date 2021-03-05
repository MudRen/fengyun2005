#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "eterne"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1508220565"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "风之叹息");
set("long", @LONG


笑江湖浪迹十年游，空负少年头。
对铜驼巷陌，吟情渺渺，心事悠悠。
酒醒诗残梦断，南国正清秋。
把剑凄然望，无处招归舟。
明日天涯路远，问谁留楚佩，弄影中州。
数英雄儿女，俯仰古今愁。
难消受灯昏罗帐，怅昙花一现恨难休。
飘零惯，金戈铁马，拼葬荒丘。


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
