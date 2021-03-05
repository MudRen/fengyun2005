#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 80
#define R_FLAG 32
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "kongkong"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1507216058"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "破庙");
set("long", @LONG
一座破破烂烂的庙，堂前供奉的不知道是哪路神仙，雕像残缺不全，透露着神秘的气息。破旧的供桌上放着猪头肉，红烧狗肉，白煮大肠，冒着热气，还有半壶酒。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword2.c",
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
