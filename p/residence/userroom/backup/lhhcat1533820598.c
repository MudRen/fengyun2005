#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 120
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "lhhcat"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533820598"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "亮晶晶");
set("long", @LONG
指尖轻触玻窗，嗤嗤的响声，惊动了脆弱的心脏，一阵阵的酸楚，像浪潮般袭来，若果这样酸酸的痛可以代替撕心裂肺，那就让他长久点，这样时间会把我忘记，这样便可躲在这里，让那些软弱手舞足蹈，让那些脆弱和不堪拼命娱乐，让那颗紧绷的心，少少松弦

LONG
);
        set("exits", ([
"out" : "/p/residence/smile3.c",
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
