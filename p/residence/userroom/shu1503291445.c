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

#define OWNER "shu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503291445"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "相见时难");
set("long", @LONG

　　相见时难别亦难，
　　东风无力百花残。
　　春蚕到死丝方尽，
　　蜡炬成灰泪始干。
　　晓镜但愁云鬓改，
　　夜吟应觉月光寒。
　　蓬山此去无多路，
　　青鸟殷勤为探看。


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
