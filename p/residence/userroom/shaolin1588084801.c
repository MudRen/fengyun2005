#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "shaolin"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1588084801"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "山居禅室");
set("long", @LONG
在风云城左近的群山之巅有一块十分光滑整洁的平台如一块玉盘落入山水之间一座实木结构为主体以细密结实茅草为顶的小屋坐落于玉盘之上古朴的门窗让整个小屋显示出颇多出尘味道一块楠木牌挂在门梁正中山居禅室四个禅意浓重的描金字恰似画龙点睛的一笔让整个意境如入仙境

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
