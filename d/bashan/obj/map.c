#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("幽溟护符", ({ "amulet"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚漆黑的护身符，能随时让你脱离(exit)石屋迷阵。\n");
		set("value", 1);
		set("lore",1);
		set("no_drop",1); 
		set("no_sell",1);
		set("no_pawn",1);
		set("no_stack",1);
	}
    ::init_item();
}

void init()
{
	add_action("do_exit","exit");
}

int do_exit()
{
	object center;
	if (!environment(this_player())->query("room_num"))
		return notify_fail("幽溟护符只能在巴山石屋迷阵中使用。\n");
	center = find_object("/d/bashan/couplemaze_center");
	if (!center)
		center = load_object("/d/bashan/couplemaze_center");
	if (!center)
		return notify_fail("错误#12100。\n");
	center->close_all_path();
	center->kickout_ppl();
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

