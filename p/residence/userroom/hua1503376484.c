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

#define OWNER "hua"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503376484"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "蝶恋花");
set("long", @LONG

　　槛菊愁烟兰泣露，
　　罗幕轻寒，燕子双飞去。
　　明月不谙离恨苦，
　　斜光到晓穿朱户。

　　昨夜西风凋碧树，
　　独上高楼，望尽天涯路。
　　欲寄彩笺兼尺素，
　　山长水阔知何处？

。

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
