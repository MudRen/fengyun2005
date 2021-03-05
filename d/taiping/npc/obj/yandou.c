#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIW"烟斗"NOR, ({ "yandou" }) );
   	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        	set("long", "这是一个很普通的烟斗，里面装满了烟草，如果你喜欢可以抽（ｓｍｏｋｅ）几口。\n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N从怀里磨磨蹭蹭地掏出一个$n握在手中。\n");
        	set("unwield_msg", "$N将手中的$n收了起来。\n");
	}
    	::init_hammer(20);
}


void init(){
	if (userp(environment(this_object())))
		add_action("do_smoke","smoke");
	return;
}



int do_smoke(){
	message_vision(WHT"$N拿起烟斗，唆着嘴狂抽几下，长长吐了口气，活神仙呀！！\n"NOR,this_player());
	if (!this_player()->query_condition("cough"))
		this_player()->apply_condition("cough",random(10)+10);
	return 1;
}


