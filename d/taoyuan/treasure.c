#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "小山洞中");
        set("long", @LONG
原来桃花源外尚隐藏着这么一个小小的山洞，你好奇地打量着四周，但见山壁
上沁出层层的水珠，似乎还描绘着一幅美丽的飞天旋舞图。向山洞的深处行去，只
可见一块突兀的奇石阻在路上，拦住了你前进的脚步。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"fenghuo",
  	"north" : __DIR__"treasureroom",
	]) );

	set("objects", ([
//		"/obj/treasure/npc/rock" : 1,
	]) );


	set("item_desc", ([
		"north" : "大石头挡在这条路上。\n",
	]) );

	set("no_fly", 1);

	set("max_lv",15);	// 阻止15级以上角色进入
	set("min_lv",5);	// 阻止5级以下角色进入
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"fenghuo");
	if (!exitroom)
		exitroom = load_object(__DIR__"fenghuo");
	if (userp(me))
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") 
		|| exp_to_level(me->query("combat_exp"))["level"] <= query("min_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"你走进山洞，左右看看，什么也没发现，垂头丧气地走了出来。\n"NOR);
	}
}


int	valid_leave(object who, string dir)
{
	if (dir == "north" && present("giant rock",this_object()))
		return notify_fail("大石不偏不倚地横在洞壁之间，挡住了你的脚步。\n");
	return ::valid_leave(who,dir);
}
