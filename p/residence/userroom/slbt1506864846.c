#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "slbt"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506864846"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "寻仙居");
set("long", @LONG
我家二楼北端有一间宽敞明亮的书房，面积大约二十平方米呢。书房里摆满了各种我喜爱的书籍，下面让我带你参观一下：书房的北面有一扇大大的飘窗，晚上坐到窗台上可以看月亮、看星星。飘窗左边有一张乳白色和绿色搭配而成的苹果形书桌。放学回家后，我就在这张书桌前看书、写作业。书房南边，有一个很宽、很大的书架，上面塞满了书，有《格林童话》、《一千零一夜》、《西游记》、《红楼梦》等。它们站成一排，远远看去，整整齐齐，好似一排威武的士兵！

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
