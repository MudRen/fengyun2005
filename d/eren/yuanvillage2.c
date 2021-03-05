inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "白云山庄大厅");
        set("long", @LONG
大厅里铺着大红的地毯，墙上点着一十八支通红的牛油巨烛。大厅的尽头处挂着
张很大的“喜”字，金色的字，鲜红的绸。红是吉祥的，象征着喜气。
LONG       );
        set("exits", ([ 
		"south" : __DIR__"yuanvillage",
		"east": __DIR__"yuanvillage3",
	]));
        set("objects", ([
		__DIR__"npc/yuanqiuyun": 1,
		__DIR__"npc/liudonglai": 1,
	]) );
	set("coor/x",-50);
        set("coor/y",30);
        set("coor/z",10);
	set("map","eren");
	setup();
}


int valid_leave(object me, string dir)
{
 	if (QUESTS_D->verify_quest(me,"白云喜筵"))
		QUESTS_D->special_reward(me,"白云喜筵");  
	return 1;
}