#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "石洞里");
        set("long", @LONG
一个石洞……
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
]));
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",0);
	setup();

	set("underwater",30);
	set("water_damage",2);

	set("no_fly", 1);
	set("max_lv",15);	// 阻止15级以上角色进入
}



void init(){
	object me = this_player();
	object exitroom = find_object(__DIR__"bottom2");
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	if (!exitroom)
		exitroom = load_object(__DIR__"bottom2");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,HIB"一阵暗流涌来，将你推离神水宫分舵。\n"NOR);
	}


}
