#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 80
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "yue"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503389452"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "秋夜月");
set("long", @LONG

　　当初聚散。便唤作、无由再逢伊面。
　　近日来、不期而会重欢宴。
　　向尊前、闲暇里，敛著眉儿长叹。
　　惹起旧愁无限。

　　盈盈泪眼。漫向我耳边，作万般幽怨。
　　奈你自家心下，有事难见。
　　待信真个，恁别无萦绊。
　　不免收心，共伊长远。


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
