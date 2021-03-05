#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "小厅");
	set("long", @LONG
这座小厅看起来是幽灵山庄的柴房，屋子中堆积满了木柴和尘土，看上去丝毫
没有别致之处，可满屋的木柴中间竟然站了个很妙的人，这人竟穿着一身看起来脱
凡超俗、和柴房格格不入的道服，最妙的是这个穿着很妙衣服的妙人还在劈柴，劈
出来的每一根柴火都像一把长剑般笔挺锋利。

LONG
	);
	set("exits", ([
                "north" : __DIR__"groad2",
	]));
	set("coor/x",-50);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",30);	
}


int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"groad2");
	if (!exitroom)
		exitroom = load_object(__DIR__"groad2");
        
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"小小柴房中只有一个正在劈柴的人，了然无趣。\n"NOR);
	}
}
