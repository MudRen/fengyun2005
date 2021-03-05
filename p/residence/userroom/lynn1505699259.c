#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 80
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "lynn"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1505699259"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "时光走廊");
set("long", @LONG

　　推开那扇狭小坏朽的门， 
　　我一个人在花园里徜徉。 
　　早晨的阳光甜美、明亮， 
　　露水闪烁，把花朵滋润。 
　　一切如旧，仿佛时光停止： 
　　葡萄藤缠绕的棚架和熟悉的 
　　藤椅……喷泉仍喃喃低语， 
　　老杨树的声音也依然悲戚。 
　　玫瑰颤动，恍若昔日；恍若 
　　昔日，骄傲的百合随风摇曳； 
　　每只往来的云雀都是我故知。 
　　甚至，残破的薇莉达雕像 
　　也仍在走道尽头，消瘦的 
　　身影，在木犀草的微香中。 


LONG
);
        set("exits", ([
"out" : "/p/residence/cloud2.c",
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
