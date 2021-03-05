#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"奇浓嘉嘉普"NOR);
        set("long", @LONG
“卟”一声，一团烈火突然在你的面前落下，火焰莲花般张开，一个人在莲花
般的火焰之上站了起来。不是人，也不是兽。它通体透明，却又并非无形。一根根
的骨骼清晰可见，左边的胸膛之上浮着一颗拳大的红心。心红得像要滴血，却没有
血滴下，它浑身上下一滴血都没有。莲花般的火焰忽然合拢，它又化成一团火焰飞
投向左边山海也似的烈焰。
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream6",
		"north":  __DIR__"dream4",
	]));
        set("objects", ([
        	__DIR__"npc/evil5": 1,
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