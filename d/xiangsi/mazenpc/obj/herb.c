#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"穿魂蚀骨草"NOR, ({ "grass","herb" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "株");
            set("material", "grass");
            set("long", "一株青白色的小草，隐约透着一缕死气。\n");
			set("desc_ext", "浸泡（pour）"); 
			set("no_stack",1);
			set("real",1);
			set("value",0);
			set("lore",1);
          }
	::init_item();
}


void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: pour <物品> in <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些水才能冲开草药。\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	message_vision("$N将一些" + name() + "放进" + ob->name() 
		+ "，冲成一"+ob->query("unit")+"药酒。\n", this_player());
	ob->set("liquid/name","药酒");
	destruct(this_object());
	return 1;
}

int drink_drug(object ob)
{
	object me = this_player();
	message_vision(HIR"\n$N的七窍中突然渗出鲜血，身子顿失重心，倒在地上。\n\n"NOR,me);
	me->set_temp("last_damage_from","误饮鸠酒而亡。");
	me->die();
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
