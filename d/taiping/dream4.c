#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"奇浓嘉嘉普"NOR);
        set("long", @LONG
风与雾之中，烈火与寒冰之间，竟似有一条无形的路，你就走在这一条无形的
路之上。抬头向上望一眼。上面并没有青天，只有寒冰在滚动，烈火在飞舞，风在
呼啸，雾在飘浮。天在何方？地在何处？没有头上的青天，没有脚下的大地，只有
风和雾，寒冰和烈焰。
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"dream5",
		"north":  __DIR__"dream3",
	]));
        set("objects", ([
        	__DIR__"npc/evil4": 1,
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