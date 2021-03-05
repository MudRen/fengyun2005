#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 63
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "tinkling"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533303875"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "青冥居");
set("long", @LONG
谁也不知道这里的主人是什么来历，但凡是见过她的都会为她的冷艳惊叹。封铃笙从来到这个世界起，就注定了孤独一人，没有见过父母，爱人横死，唯一的女儿不知所踪。任谁经历了这样的变故都会变得心灰意冷，一如这位美艳绝伦的道姑。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword9.c",
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
