#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "gandalf"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1507528984"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "温柔乡");
set("long", @LONG
房间当中放着一张花梨大理石大案，案上磊着各种名人法帖，并数十方宝砚，各色笔筒，笔海内插的笔如树林一般。那一边设着斗大的一个汝窑花囊，插着满满的一囊水晶球儿的白菊。西墙上当中挂着一大幅米襄阳《烟雨图》，左右挂着一副对联，乃是颜鲁公墨迹，其词云：烟霞闲骨格，泉石野生涯。案上设着大鼎。左边紫檀架上放着一个大官窑的大盘，盘内盛着数十个娇黄玲珑大佛手。右边洋漆架上悬着一个白玉比目磬，旁边挂着小锤。卧榻是悬着葱绿双绣花卉草虫纱帐的拔步床。给人的感觉是总体宽大细处密集，充满着一股潇洒风雅的书卷气。

LONG
);
        set("exits", ([
"out" : "/p/residence/sword1.c",
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
