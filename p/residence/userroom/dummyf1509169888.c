#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 80
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "dummyf"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1509169888"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "大米之家");
set("long", @LONG
岁月如歌唱，流逝如流水。当年少年子弟少年志，凭一腔热血和手中长剑闯荡江湖，谱写一曲曲热血青春。如此回首往事，早已风轻云淡去。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword2.c",
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
