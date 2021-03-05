#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 160
#define R_FLAG 1
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "seagull"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1513006766"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "得月楼");
set("long", @LONG
道可道也非恒道也名可名也非恒名也无名天地之始有名万物之母故常无欲以观其妙常有欲以观其徼此两者同出而异名同谓之玄玄之又玄眾妙之门

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
