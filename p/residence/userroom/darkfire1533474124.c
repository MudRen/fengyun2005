#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 63
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "darkfire"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533474124"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "罗喉界上");
set("long", @LONG
这里的空间极不稳定，究其原因，是因为此处正是人间界与幽界的交汇处。很难想象，有人竟然在这里建造了一间房子。虽然简陋，但也绝非普通人力所为。

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
