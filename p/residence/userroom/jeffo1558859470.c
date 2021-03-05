#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 240
#define R_FLAG 45
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "jeffo"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1558859470"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "明月楼");
set("long", @LONG
桂花香醉满月楼，风过松间玉簟秋。提灯共话夜婵娟，天上人间此千年。今时焚香见瑶台，寂寞嫦娥落九天。皓月有缘照无眠，此情自古最缠绵。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword6.c",
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
