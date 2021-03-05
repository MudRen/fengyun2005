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

#define OWNER "zen"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1512957889"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "天坛");
set("long", @LONG

天坛为历代帝王祭天之所在，神庙庄严肃穆，依“天圆地方”而建，布局呈回
字形，分内外两坛，内坛二十八根金丝楠木大柱，里圈的四根寓意春夏秋冬四
季，中间十二根寓意十二个月，最外十二根寓意十二时辰以及周天星宿。殿顶
覆盖上青、中黄、下绿三色琉璃，寓意天、地、万物，琉璃门上高悬一方金匾。


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
