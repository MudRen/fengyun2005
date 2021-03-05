#include <ansi.h>
#include <combat.h>
inherit WALL;

string heal();
void create()
{
	set_name("阿水", ({ "sinny","sandbag" }) );
	set("race","元素");
	set("desc","这是一个不大不小的沙袋，被画成阿水的样子。\n它可以用来测试你的攻击力，还可以揍来出气．．．\n");
	set("combat_exp",4000000);
	set("max_kee",40000);	// 20k,1% = 400kee
	set_skill("iron-cloth",100);
	set_skill("steelwall",100);
	map_skill("iron-cloth","steelwall");
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: heal() :),
        }) );
	set("item_type","t");
set("tax",15);
set("score_tax",1);
	set("size",1);
	setup();
}

void init()
{
   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
}


string heal()
{
	message_vision(CYN"画着阿水的大沙袋晃了晃，摆回原来的位置。\n"NOR,this_object());
	remove_all_killer();
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
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
	if (!present("dismantle statue",me))
		return notify_fail("你没有合适的工具以进行拆除。\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("错误#13108。\n");	// 天知道是什么意思...ppl report的时候当search index
	message_vision(CYN"$N一提气，扬起毁灭石像向"+name()+"上砸去，不两下就把"+name()+"砸得稀烂。\n\n"NOR,me);
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

		env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// 防bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// 防bug

	env->save();
	destruct(present("dismantle statue",me));
	destruct(ob);
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

