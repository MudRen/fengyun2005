#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 5
#define CONSTRUCT_TREE 1
#define BASIC_TAX 2240
#define BASIC_SCORE_TAX 500

#define TOTAL_GOLD 2400
#define TOTAL_SCORE 820

#define OWNER "mrsunys"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1587366761"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "墨宅");
set("long", @LONG
从明天起做一个幸福的人喂马劈柴周游世界关心粮食和蔬菜从明天起和每一个亲人通信告诉他们我的幸福那幸福的闪电告诉我的我将告诉每一个人给每一条河每一座山都取一个温暖的名字陌生人我也为你祝福愿你有一个灿烂的前程愿你有情人终成眷属愿你在尘世获得幸福我有一所房子面朝大海春暖花开

LONG
);
        set("exits", ([
"out" : "/p/residence/smile9.c",
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
