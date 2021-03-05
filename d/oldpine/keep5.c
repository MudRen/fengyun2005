#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "老云寨深处");
        set("long", @LONG
一间地上铺着虎皮地毯，四周挂满了狼皮和鹿头，还串着几个人骨骷髅的小小
房屋，房屋一角是竟然是张纯金打造的卧床，一个须发皆白却依然看得出凶悍之气
的老人正坐在床上，手里拿着根不知道什么的腿骨大口啃咬。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"keep4",
        ]));
        set("coor/x",120);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
	set("no_fly", 1);
	set("max_lv",25);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"keep3");
	if (!exitroom)
		exitroom = load_object(__DIR__"keep3");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"富有江湖历练的你暗自沉思：若贸然行事，误中埋伏，反而不妙。
既然常老大就在这里，也没有必要冒险多事。\n"NOR);
	}
}

