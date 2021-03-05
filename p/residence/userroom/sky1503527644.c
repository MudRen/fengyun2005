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

#define OWNER "sky"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503527644"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "秋夜");
set("long", @LONG

　　络纬啼歇疏梧烟，
　　露华一白凉无边。
　　纤云微荡月沉海，
　　列宿乱摇风满天。
　　谁人一声歌子夜，
　　寻声宛转空台榭。
　　声长声短鸡续鸣，
　　曙色冷光相激射。


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
