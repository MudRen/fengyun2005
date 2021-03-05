#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 160
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "huludw"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1551026949"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "帝王家");
set("long", @LONG
郁孤台下清江水中间多少行人泪西北望长安可怜无数山青山遮不住毕竟东流去江晚正愁余山深闻鹧鸪在天愿做比翼鸟在地愿为连理枝愁余山深闻鹧鸪在天愿做比翼鸟在地愿为连理枝

LONG
);
        set("exits", ([
"out" : "/p/residence/sword4.c",
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
