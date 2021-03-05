#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 63
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "psychic"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533211503"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "通灵小屋");
set("long", @LONG
这间小屋孤独地坐落在城市的边缘，无人靠近。
但奇怪的是，一只流浪狗径直穿过了它，来到小屋紧靠的大树下撒了泡尿。毫无阻碍一般。
原来，只有能穿梭阴阳两界的真正的通灵者，才能看见这个小屋。

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
