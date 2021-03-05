#define X_COOR 0
#define Y_COOR 0
#define Z_COOR 0
#define R_FLAG 0
#define FREE_SPACE 4
#define CONSTRUCT_TREE 0
#define BASIC_TAX 0
#define BASIC_SCORE_TAX 0

#define TOTAL_GOLD 0
#define TOTAL_SCORE 0

#define OWNER "bigtie7001"
#define TIMESTAMP "anniestamp"
#define CLASS "bigwiz7001"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "SHORT_TITLE");
set("long", @LONG
LONG_TITLE
LONG
);
        set("exits", ([
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
	set("free_space",FREE_SPACE);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}

