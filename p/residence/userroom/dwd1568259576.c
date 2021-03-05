#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "dwd"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1568259576"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "隐仙阁");
set("long", @LONG
大隐住朝市，小隐入丘樊。丘樊太冷落，朝市太嚣喧。
不如作中隐，隐在留司官。似出复似处，非忙亦非闲。
不劳心与力，又免饥与寒。终岁无公事，随月有俸钱。
君若好登临，城南有秋山。君若爱游荡，城东有春园。
君若欲一醉，时出赴宾筵。洛中多君子，可以恣欢言。
君若欲高卧，但自深掩关。亦无车马客，造次到门前。
人生处一世，其道难两全。贱即苦冻馁，贵则多忧患。
唯此中隐士，致身吉且安。穷通与丰约，正在四者间。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword8.c",
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
