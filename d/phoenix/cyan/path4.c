// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "山道");
    set("long", @LONG
这里的山道与其叫山道，倒不如叫做山隙更恰当些：道路仅有肩宽，左右
都是坚硬的花岩，惟有一丝微弱的光芒自头顶的石缝中漏下。借着微光，你隐
可看见窄缝中洒满了凌乱而且锋利的碎石，节节爬高，不知通向何方。
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/container":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "forest3",
  		"westup" : "forest4",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;
		if (REWARD_D->riddle_check(me,"韶光虚掷") == 99) 
		{
			return notify_fail("你的去路被今田挡住了！\n");
		}

			REWARD_D->riddle_set(me,"韶光虚掷",99);
			who=new(__DIR__"npc/j2");
			who->move(this_object());
			message_vision(HIR BLK"灰黑色的烟雾骤然在你眼前爆开，烟雾散去，竟凭空现出一个人影。\n"NOR,me);
			message_vision(HIR"$N自鼻子里哼道：中原人．．．到此为止了。\n\n"NOR,who);	// not typo.
			who->kill_ob(me);
			me->kill_ob(who);
			return notify_fail("\n");

	return ::valid_leave(who,dir);
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


