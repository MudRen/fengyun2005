// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "无间堂入口");
	set("long", @LONG
也不知走了多久，黑血甬道终于到了尽头，前面是一间十分开阔的大堂，四角
高燃着牛烛，却是一种绿色的火焰，堂门大开，里面烟雾缭绕，数丈开外便感到那
灼人的热浪，若不是内功有些根基的，呆不了片刻便会晕倒。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq2-maze/exit",
		"east" : __DIR__"jq2-end",

	]));
        set("objects", ([
                
        ]) );
        set("item_desc", ([
		"east": "堂内烟雾滚滚，远远看去什么也看不到，只感到那灼人的热浪。\n",
	]) );
	setup();
	
}

int	valid_leave(object who , string dir) {
	object room, guo;
	
	if (dir == "east") 
	{
		room = find_object(__DIR__"jq2-end");
                if (room && room->usr_in())
			return notify_fail("堂内热焰滚滚，隐约有人影晃动。\n");
		if (REWARD_D->riddle_check(who,"再闯金钱")<2) 
			return notify_fail("堂内热焰滚滚，没事儿还是别进去了吧。\n");
		if (room) {
			if (guo = present("guo songyang",room))
				destruct(guo);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}