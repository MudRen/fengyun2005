// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "山道");
    set("long", @LONG
这里的山道与其叫山道，倒不如叫做山隙更恰当些：道路仅有肩宽，左右
都是坚硬的花岩，惟有一丝微弱的光芒自头顶的石缝中漏下。借着微光，你隐
可看见窄缝中洒满了凌乱而且锋利的碎石，节节爬高，不知通向何方，更有一
根竹竿插在左侧的岩壁里。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/test":1,
	__DIR__"npc/ouyang":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : __DIR__"peak7",
  		"westdown" : __DIR__"peak5",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",80);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (!random(3))
	{
		tell_object(me,CYN"你在狭窄的山缝中艰难前行。\n"NOR);
		me->perform_busy(1);
	}
	else if (!random(3))
	{
		tell_object(me,CYN"你努力挤过一处狭窄的山路，不小心踩到锋利的碎石，痛彻心扉。\n"NOR);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","在山道中碰个头破血流，力竭而亡。");
	}
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


