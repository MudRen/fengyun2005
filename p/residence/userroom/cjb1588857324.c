#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "cjb"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1588857324"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "存货站");
set("long", @LONG
这是一所普通的房子可怜的房主由雨滴赞助了贰佰两才能做个这样的房子这个房子就是专门用来存放特殊物品的虽然好像也没有甚么鸟用希望有一天房主能打出个好一点的装备不然对不起这个价钱还要凑足六十个字我想我的语文知识已经还给我的语文老师了

LONG
);
        set("exits", ([
"out" : "/p/residence/smile9.c",
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
