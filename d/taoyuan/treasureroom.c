#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "小山洞深处");
        set("long", @LONG
小小的山洞深处．．．
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"treasure",
	]) );

	set("objects", ([

	]) );

	set("no_fly", 1);

	set("max_lv",15);	// 阻止15级以上角色进入

	set("coor/x",-20);
	set("coor/y",40);
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
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"你走进山洞，左右看看，什么也没发现，垂头丧气地走了出来。\n"NOR);
	}
}
