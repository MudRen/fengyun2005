#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "fire"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1512709616"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "明霞听雪");
set("long", @LONG

阳光自明瓦窗隙间斜照进来，映出流萤般飞舞着的点点浮尘，窗边
坐着个明眸女子，信手拈着盏官窖酒杯，细腻腻的永乐甜白瓷，盈
盈一握于指间，轻轻旋转。空气里缭绕着若有似无的艾蒲香，是如
斯的雅媚，小巧玲珑的烟水小楼，坐落在枕霞之城一侧的雪原东边。


LONG
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
