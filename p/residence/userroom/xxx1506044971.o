#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 35
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "xxx"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506044971"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "狐狸窝");
set("long", @LONG
床前明月光，疑是地上霜。
举头望明月，低头思故乡。
这首诗写的是在寂静的月夜思念家乡的感受。诗的前两句，是写诗人在作客他乡的特定环境中一刹那间所产生的错觉。一个独处他乡的人，白天奔波忙碌，倒还能冲淡离愁，然而一到夜深人静的时候，心头就难免泛起阵阵思念故乡的波澜。何况是在月明之夜，更何况是月色如霜的秋夜。“疑是地上霜”中的“疑”字，生动地表达了诗人睡梦初醒，迷离恍惚中将照射在床前的清冷月光误作铺在地面的浓霜。而“霜”字用得更妙，既形容了月光的皎洁，又表达了季节的寒冷，还烘托出诗人飘泊他乡的孤寂凄凉之情。

LONG
);
        set("exits", ([
"out" : "/p/residence/tower1.c",
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
