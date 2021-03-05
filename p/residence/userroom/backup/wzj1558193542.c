#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "wzj"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1558193542"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "美人居");
set("long", @LONG
白玉堂前春解舞东风卷得均匀蜂团蝶阵乱纷纷几曾随逝水岂必委芳尘万缕千丝终不改任他随聚随分韶华休笑本无根好风频借力送我上青云

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
