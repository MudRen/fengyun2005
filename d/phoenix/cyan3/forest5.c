// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"黄树林"NOR);
    set("long", @LONG
挤出狭窄的山缝，迎接你的是一片奇特的树林。从未见过的各种参天巨木
如列阵般在黑软的淤泥上排布得井然有序，远远看去，犹如墨盘上还未动过的
木棋。仰头上望，但见覆满苍穹的木叶竟无一片苍碧，满满漾着浅浅的鹅黄，
枝条如镀金边，构筑为一种奇异诡谲的美丽。
    不知名的季节，微风。
    金色的光线从树顶中浅浅地透了下来。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northdown" : "peak5",
  		"southdown" : "forest4",
	]) );
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	// 3 ways to pass: 
	// kill 2 keepers (set mark to 5);
	// get invition (set mark to 6);
	// or rob the 请柬 (set mark to 7)
	if (present("shaolin monk") && dir == "southdown")
		if (!REWARD_D->check_m_success(me,"杀和尚") && !REWARD_D->check_m_success(me,"溜过去") && !REWARD_D->check_m_success(me,"请柬") )
			return notify_fail("少林派和尚道：阿弥陀佛，这位施主还请留步。\n");

	if (!random(7))
		tell_object(me,YEL"你隐隐闻到了一种淡淡的金色的香气。\n"NOR);

	if (dir == "southdown")
		if (REWARD_D->riddle_check(me,"天涯魂梦") >= 4) 
			if (REWARD_D->riddle_check(me,"天涯魂梦") <= 6) 
				REWARD_D->riddle_set(me,"天涯魂梦",7);
					


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


