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

#define OWNER "tanghulu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1590924560"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "糖葫芦加工厂");
set("long", @LONG
这里是风云城里最大的南北货集市不少名流商贾每天流连在这里除了常见的生活用品和一些土特产品以外从各地来的奇珍异宝都能在这里得见有名满天下的南珠也有产自西域的汗血宝马更有来自苏杭一带的丝绸刺绣及胭脂水粉还有不远千里远渡重洋的商船队带来异邦的各种稀奇的玩意还有最爱的糖葫芦

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
