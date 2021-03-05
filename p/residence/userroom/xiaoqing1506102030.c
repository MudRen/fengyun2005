#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 3
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "xiaoqing"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506102030"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "潇湘夜雨楼");
set("long", @LONG
玉盘银冷桂花路，残香红暖宿星街
指抱离壶秋深浅，月落愁杯看盈缺
洁然洁然无酒色，味比前年后院雪
雪润愁肠魂先醒，寒影寒心寒时觉
人持芳枝勤相邀，笑跃唇齿语不歇
微眼沉眉忙推就，颊染胭脂鬓乌夜
醉非好醉应独醉，夜在重阳不堪歇
莫怪月满不留君，留君最属君庭月

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
