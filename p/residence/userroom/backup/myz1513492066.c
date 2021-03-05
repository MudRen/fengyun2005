#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 80
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "myz"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1513492066"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "狐狸窝");
set("long", @LONG
我们的人生也是需要原型的。每个人的一生其实就是一个故事，你是你生命的主人公，也是你故事的作者。从呱呱坠地到离开人世，你用一生的时间在书写你自己这个作品。你这个作品是否精彩，取决于你身为作者是不是用心在书写。用心书写的一个重要标志，就是为自己的生命寻找原型。我们发现，那些伟大人物在他成长的历程中，总是有自己的生命原型，总是以某些人作为自己的榜样，作为自我的镜像。越是这样的人，他人生越有目标，他越是能够走得更远

LONG
);
        set("exits", ([
"out" : "/p/residence/tower2.c",
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
