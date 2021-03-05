#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(CYN"扁扁的酒葫芦" NOR,({"wine"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "wood");
		set("long",CYN"一个扁扁的酒葫芦，里面装的酒颜色发黑，闻起来连点酒味都没有。\n"NOR);
		}
    ::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_drink","drink");
}

int do_drink(string arg)
{
	object me;
	me = this_player();
	if (!arg)
		return notify_fail("你要喝什么？\n");
    if (arg != "wine")
		return notify_fail("你要喝什么？\n");
	if (query("used")) 
		return notify_fail(this_object()->name()+"已经被喝光了。\n");
    message_vision(HIG"$N捧起扁扁的酒葫芦，喝了一大口怪怪的酒。\n"NOR,me);
    message_vision(HIC"\n$N觉得肚子里却好像忽然燃起了堆火，不禁一张口，一道酒箭激喷而出。\n"NOR,me);
	if (REWARD_D->riddle_check(me,"两世恩怨") == 8)
	    environment(this_player())->wine_notify(me);
	set("used",1);
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
