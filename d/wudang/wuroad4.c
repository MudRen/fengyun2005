#include <command.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后院门");
	set("long", @LONG
青石小路穿过了花丛，到这里为止。一个小小的月形门立在此处。门上的墙壁
上刻著“后院”两个字。门旁挂著一块木牌，上写  [1;37m非武当弟子，请勿擅入[0;32m
LONG
	);
	set("exits", ([ 
		"enter" : __DIR__"wudang3",
  		"west" : __DIR__"wuroad3",
	]));
	set("outdoors", "wudang");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
	
	
int valid_leave(object me, string dir)
{
        int i;
        object *inv/*, ro*/;

        if( dir != "enter" ) return 1;
		if (!userp(me))	return 1;
		
        if (me->query("family/family_name")=="武当派" || me->name()=="彭长净" )
        	return 1;
		
		if (REWARD_D->riddle_check(me,"新手入门"))
			return notify_fail("石雁真人在紫霄宫，向回走才对。\n");
		
		message_vision(HIY "忽然身後有几个声音大叫：＂有贼呀！来抓贼呀！＂\n"NOR, me);
    	message_vision(HIR "接著「咚」地一声，$N的脑后被人重重地打了一棍。\n"NOR, me);
    	me->unconcious();
    	message_vision(HIY "两个武当道士把$N所有的东西搜了一遍，把$N重重地摔在了地上，然后转身离开了。\n"NOR, me);	
    	inv = all_inventory(me);
    	for(i=0; i<sizeof(inv); i++) {
    		if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
			destruct(inv[i]);
        }
        return notify_fail("");
}
