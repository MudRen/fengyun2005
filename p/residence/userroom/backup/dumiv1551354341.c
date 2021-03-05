#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "dumiv"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1551354341"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "风雪崖");
set("long", @LONG
欲渡黄河冰塞川，将登太行雪满山。
    闲来垂钓碧溪上，忽复乘舟梦日边。
    行路难！行路难！多歧路，今安在？
    行路难！行路难！多歧路，今安在？

LONG
);
        set("exits", ([
"out" : "/p/residence/tower8.c",
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
