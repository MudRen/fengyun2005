#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"奇浓嘉嘉普"NOR);
        set("long", @LONG
惊顾四周。这刹那之间，在你的四周竟全部塞满了“人”。有些随风飘飞，有
些雾中隐现，滚动的寒冰之内更是不计其数。这些“人”也不知来自何方，倒像是
一直都存在，现在才现身出来。它们并不是“人”。它们是妖魔。九天十地的妖魔，
各式各样的妖魔。风中，雾中，烈火中，寒冰中，没有一处地方不看见这些妖魔。
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream7",
		"north":  __DIR__"dream5",
	]));
        set("objects", ([
        	__DIR__"npc/evil6": 1,
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int valid_leave(object me,string dir) {
        object evil;
	
	if( userp(me) && dir == "south") {
		evil=present("evil",this_object());
		if (evil) 
		if (!evil->query("statue")){
			message_vision(HIW+evil->name()+"挡住了$N前进的道路。\n"NOR,me);
			return notify_fail("");
		}
	}
	return 1;
}