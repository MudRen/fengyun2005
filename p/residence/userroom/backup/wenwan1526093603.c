#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 120
#define R_FLAG 33
#define FREE_SPACE 5
#define CONSTRUCT_TREE 1
#define BASIC_TAX 2240
#define BASIC_SCORE_TAX 500

#define TOTAL_GOLD 2400
#define TOTAL_SCORE 820

#define OWNER "wenwan"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1526093603"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "大喇嘛");
set("long", @LONG
 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！ 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！ 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！ 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！ 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！

LONG
);
        set("exits", ([
"out" : "/p/residence/smile3.c",
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
