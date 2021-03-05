// TIE@FY3
#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
	set_name(HIW"天一神水"NOR, ({ "tianyi poison", "poison" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是一种无色，无味，奇毒无比的液体，可以滴在(di)在酒水之中害人。\n" );
		set("unit", "滴");
//        set("base_value", 700);
		set("base_unit", "滴");
		set("base_weight", 30);
	}
	set_amount(1);
}
void init()
{
	add_action("do_pour", "di");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: di <神水> in <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些液体才可以。\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/slumber_effect", 100);
	message_vision("$N将一滴" + name() + "小心翼翼地倒进" + ob->name() 
		+ "，摇晃了几下。\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("tianyi",
		(int)this_player()->query_condition("tianyi") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}
