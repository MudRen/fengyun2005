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

#define OWNER "liu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503379346"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "淡黄柳");
set("long", @LONG

　　空城晓角，吹入垂杨陌。
　　马上单衣寒恻恻。
　　看尽鹅黄嫩绿，
　　都是江南旧相识。

　　正岑寂。明朝又寒食。
　　强携酒，小桥宅。
　　怕梨花落尽成秋色。
　　燕燕飞来，问春何在，
　　唯有池塘自碧。


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
