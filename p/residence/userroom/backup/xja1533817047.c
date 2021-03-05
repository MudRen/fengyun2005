#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 120
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "xja"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533817047"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "微雨燕双飞");
set("long", @LONG
一直执着于生命的简约格调，只愿用一颗淡然的心看云卷云舒，看季节更迭。许多不合时节的事物，必然会被光阴遗落，就像曾经繁茂的秋叶，待生命枯竭，终将脱离叶脉的相系相牵。而我，一直在这里，抖落一身的负累，永恒以树的姿态站立于季风中，昂首向着那无边温暖的碧蓝晴空

LONG
);
        set("exits", ([
"out" : "/p/residence/smile3.c",
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
