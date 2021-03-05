#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 63
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "paladin"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533573720"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "光明圣堂");
set("long", @LONG
燕明蓉到底是什么种族，其实早已经不那么重要。身为当世最强大的四个光明圣法师之一的她，罕见地被人、妖和灵三届都奉为传奇。
当然，在妖族的心中，她的地位更加超然，隐隐位居四大之首。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword9.c",
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
