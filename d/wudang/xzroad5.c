
#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "街道");
	set("long", @LONG
用青石板铺成的道路，打扫得干乾净净。几个小童在街道上互相追逐玩耍。街
道两旁是红砖砌成的房屋，两位老者悠闲地坐在家门前吸烟聊天。
LONG
	);
	set("exits", ([ 
        "northeast" : __DIR__"xzroad3",
//        "southwest" : __DIR__"xzroad4",
	]));
	set("outdoors", "wudang");
	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",-50);
	setup();
	set("no_fly", 1);
	set("max_lv",35);	
}


int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"xzroad4");
	if (!exitroom)
		exitroom = load_object(__DIR__"xzroad4");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"小镇道路千回百转，你转了几圈，晕了方向。\n"NOR);
	}
}

