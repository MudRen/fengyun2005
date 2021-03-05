inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南宫钱庄");
        set("long", @LONG
中原南宫世家，家财万贯，产业不可胜数。此间钱庄黑匾红字，正是南宫产业
之一。南宫钱庄的银票信誉极好，大江南北都可兑现。钱庄中央有一红木柜台，半
人多高，上有牌（ｓｉｇｎ）一块。
LONG
        );
        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

convert     兑换钱币。
withdraw    提取存款。
deposit     存入钱币。
balance     察寻存款。
loan        向钱庄借钱。
transfer    直接转帐。

TEXT
        ]) );


        set("objects", ([
                __DIR__"npc/bankowner" : 1,
        ]) );
        
        set("exits", ([ 
		"north" : __DIR__"vroad3",
	]));

	set("coor/x",70);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();

}
