#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("草丛", ({ "grass"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "丛");
	set("long", "细窄水道的两边，青碧的野草长得分外茂密。\n");
	set("desc", "青碧的野草长得分外茂密。\n");
	set("no_sell",1);
	set("no_stack",1);
	set("no_reset",1);
		set("no_drop",1); 
	set("item_type","j");
	set("outdoors",1);
	set("size",1);
	set("lore",1);
	set("value", 0);
	seteuid(getuid());
}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");

	if (environment()->query("short") != "潮径")
	{
		set("no_shown",0);
		add_action("do_look","look");
		add_action("do_dismantle","dismantle");
	}
	else
		set("no_shown",1);

}

int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("错误#13106。\n");	// 天知道是什么意思...ppl report的时候当search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("家庭用品只能由屋子的主人拆除。\n");
	if (!present("fatangel statue",me))
		return notify_fail("你没有合适的工具以进行拆除。\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("错误#13108。\n");	// 天知道是什么意思...ppl report的时候当search index
	message_vision(CYN"$N一提气，扬起胖天使的石像向"+name()+"上砸去，不两下就把"+name()+"砸得稀烂。\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));
	env->save();
	destruct(ob);
	destruct(present("fatangel statue",me));
	return 1;	
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
	if (wizardp(this_player()))
		set("long",query("desc")+"仔细看去，隐约可见几个小字：江门铸造。\n");
}



int do_install(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!arg)
		return notify_fail("你要安装什么东西？\n");
	if (present(arg,me) != ob)
		return 0;
	if (!env)
		return notify_fail("错误#13107。\n");	// 天知道是什么意思...ppl report的时候当search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("家庭用品只能由屋子的主人放置。\n");
	if (env->query("free_space") - query("size") < 0)
		return notify_fail("屋子里没有足够的空间可以放置"+name()+"。\n");
	if (env->query("outdoors") && !query("outdoors") )
		return notify_fail(name()+"只能被放置在室内。\n");
	if (!env->query("outdoors") && query("outdoors") )
		return notify_fail(name()+"只能被放置在室外。\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("这类东西每间屋子里只能放一个。\n");
	move(env);
	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));
	env->set("item_list/"+env->query("item_index"),base_name(ob));

	env->save();
	write("Ok.\n");
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
