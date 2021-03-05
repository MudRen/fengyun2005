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
	__DIR__"npc/guard1":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "forest3",
  		"westup" : "forest4",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}



int	valid_leave(object who, string dir)
{
	object me;
	string msg;
	me = who;

	if (present("shaolin monk") && dir == "eastdown" && userp(who))
		if (!REWARD_D->check_m_success(me,"再杀和尚") && !REWARD_D->check_m_success(me,"托名九秀山庄") && !REWARD_D->check_m_success(me,"托名清平") )
		{
				me->set_temp("aaa",1);
				return notify_fail("少林派和尚道：阿弥陀佛，请问这位施主是何派"CYN"高足"NOR"？("HIW"answer"NOR")\n");
		}

	if (dir=="eastdown" && userp(who))
		me->perform_busy(3);

	if (!random(7))
		tell_object(me,YEL"你隐隐闻到了一种淡淡的金色的香气。\n"NOR);

	return ::valid_leave(who,dir);
}


void reset()
{
        object *inv, ob;
        int i;
        ::reset();
        ob=present("shaolin monk", this_object());
        inv = all_inventory();
        if(ob)
		{
			ob->dismiss_team();
			for(i=0;i<sizeof(inv);i++)
				if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
					ob->add_team_member(inv[i]);
        }
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


