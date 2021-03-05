#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "yyg"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1508028392"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "风月楼");
set("long", @LONG
东菱歌怨木兰舟 岳客魂消百尺楼
大似洛妃乘雾去 帝天无际水空流

西施越溪女 出自苎萝山
秀色掩今古 荷花羞玉颜
浣纱弄碧水 自与清波闲
皓齿信难开 沉吟碧云间
勾践徵绝艳 扬蛾入吴关
提携馆娃宫 杳渺讵可攀
一破夫差国 千秋竟不还

LONG
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
