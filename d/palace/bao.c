#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "神水宫分舵");
        set("long", @LONG
这里是神水宫秘密分舵之一，但现在已经废弃不用了。南面似乎有一个
石洞，洞口封着一块礁岩，周围长满了水草，却不见鱼虾游动。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
  "south" : __DIR__"bao2",
]));
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",0);
	setup();

	set("item_desc", ([
		"south" : "礁岩彻底将洞口封住了。\n",
	]) );

	set("underwater",30);
	set("water_damage",2);

	set("no_fly", 1);
	set("max_lv",20);	// 阻止20级以上角色进入
	set("min_lv",5);
}


int	valid_leave(object who, string dir)
{
	if (dir == "south" && present("moss rock",this_object()))
		return notify_fail("礁岩彻底将洞口封住了。\n");
	return ::valid_leave(who,dir);
}

void init(){
	object me = this_player();
	object exitroom = find_object(__DIR__"bottom2");
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	if (!exitroom)
		exitroom = load_object(__DIR__"bottom2");
	if (userp(me))
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv")
		|| exp_to_level(me->query("combat_exp"))["level"] <= query("min_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,HIB"一阵暗流涌来，将你推离神水宫分舵。\n"NOR);
	}


}
