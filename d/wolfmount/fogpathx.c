#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "云雾石径");

	set("long", @LONG
山中云雾缭绕，小路蜿蜒而上，一丛丛不知名的小花在山风中摇曳，正值花落
时节，斜斜的石径上落花缤纷。踏着落花，“沙沙”之声在寂静的山谷中似乎格外
清晰，风中也充满了干燥木叶和百花的芬芳，青天下远山如翠。
LONG);

	set("type","road");
	set("exits",([
        "westdown":__DIR__"fogpath3",
	]) );
        set("objects", ([
                __DIR__"obj/dropflower" : 1,
       ]) );
	set("coor/x",60);
	set("coor/y",-40);
	set("coor/z",20);
       set("outdoors", "wolfmount");

	setup();

	set("no_fly", 1);
	set("max_lv",85);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"fogpath3");
	if (!exitroom)
		exitroom = load_object(__DIR__"fogpath3");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"此处过去是狼山招待前来投奔之人的地方，还是不去为上。\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

