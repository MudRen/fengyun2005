// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "赤兀岭");
    set("long", @LONG
从百怒峰下来，过得赤兀岭便是号称极地之险、穷路之峻，直上青云，亘
立中天，非世间豪杰无法涉足的争雄之崖。抬眉展望，但见青山巍峨迤逦，峥
嵘压顶，直似要铺天盖地地冲你倒压下来，比起在百怒峰上远眺，又是另外一
分光景。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/bored":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : __DIR__"peak9",
  		"southup" : __DIR__"peak6",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",60);
	set("coor/z",80);
	setup();
}


int valid_leave(object obj, string dir){
	object w;
	int i;
	if (userp(obj))
	{
		i=20;
		w = obj->query_temp("weapon");
		if (w)
			if (w->query("skill_type") == "spear" || w->query("skill_type") == "staff")
				i=1;
		if (dir == "northup" && random(i))
		{
			obj->receive_damage("kee",200);
			message_vision(RED"$N气喘吁吁，努力向前行去．．．\n"NOR,obj);
			obj->move(this_object());
			return notify_fail("");
		}
		if (w)
			message_vision("$N拄着"+w->name()+NOR"气喘吁吁地爬上了崖顶。\n"NOR, obj);
	}
	return 1;
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


