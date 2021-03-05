#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"奇浓嘉嘉普"NOR);
        set("long", "这一步跨出，你突然瞥见了炽烈的光芒。"+HIR"火光！"NOR+"飞扬的火焰，排山倒海般正从
你的右方涌来。仓皇左顾，左方没有火焰，只有冰。"+HIW"寒冰！"NOR+"狂流奔沙一样的寒冰，
映着火光，索索滚动。火已烧来，冰已滚到，烈火寒冰之间却有相隔半丈的一段空
隙，你就置身这空隙之中。\n"NOR
        );
        set("exits", ([ 
//		"down":  __DIR__"dream2",
		"south":  __DIR__"dream4",
	]));
        set("objects", ([
        	__DIR__"npc/evil3": 1,
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