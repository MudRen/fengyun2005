#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "树林");
        set("long", @LONG
树林中古木参天，阴霾蔽日；四周杀气阵阵，空气中涌动着新鲜的血腥味
道，然而方才听见的兵刃交击之声已然消失，只见地上横七竖八地躺着几具身
著黑衣的尸体，一个嘴角犹带鲜血的少年背后插着一柄染红的长剑站在尸体中
间，面容坚忍。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "northwest" : __DIR__"sroad5",
	]));
        set("outdoors", "fengyun");
	set("coor/x",300);
	set("coor/y",-320);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",60);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"sroad5");
	if (!exitroom)
		exitroom = load_object(__DIR__"sroad5");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"树林中杀气重重，你的江湖历练警告你不要轻易入内。\n"NOR);
	}
}

