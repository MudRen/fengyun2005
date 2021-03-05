#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"奇浓嘉嘉普"NOR);
        set("long", @LONG
也不知走了多久，走了多远。周围还是风和雾，烈焰与寒冰。左右的烈焰寒冰
陡然壁立。烈火结成了火墙，寒冰凝成了冰壁。冰壁火墙中群魔再现，肃立在两旁。
一座华丽已极的宫殿几乎同时出现在你的眼前。这座宫殿简直就像是天外飞来，却
又上不接天，下不及地，仿佛飘浮在风雾中。
LONG
        );
        set("exits", ([ 
		"up":  __DIR__"dream8",
		"north":  __DIR__"dream6",
	]));
        set("objects", ([
        	__DIR__"npc/evil7": 1,
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
	
	if( userp(me) && dir == "up") {
		evil=present("evil",this_object());
		if (evil) 
		if (!evil->query("statue")){
			message_vision(HIW+evil->name()+"挡住了$N前进的道路。\n"NOR,me);
			return notify_fail("");
		}
	}
	return 1;
}