#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("大沙包", ({ "sand bag"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个大大大大大沙包。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","l");
	set("size",1);
	set("value", 1000000);
	set("tax",20);
	set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");
   	add_action("do_look","look");
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
//	if (env->query("outdoors") && !query("outdoors") )
//		return notify_fail(name()+"只能被放置在室内。\n");
//	if (!env->query("outdoors") && query("outdoors") )
//		return notify_fail(name()+"只能被放置在室外。\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("这类东西每间屋子里只能放一个。\n");

	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));

	env->add("tax",query("tax")*7);
	env->add("score_tax",query("score_tax")*100);

	ob = new(__DIR__"sandbag");
	env->set("item_list/"+env->query("item_index"),base_name(ob));
	ob->move(env);

	env->save();
	write("开始安装"+ob->name()+"。。。安装完毕！\n");
	destruct(this_object());
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
