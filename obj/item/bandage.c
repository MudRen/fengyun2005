
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("布条", ({ "bandage"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "条");
		set("base_weight",20);
		set("unit", "束");
		set("volumn",5);
		set("material", "cloth");
		set("armor_type", "bandage");
		set("desc_ext","裹伤（ｂａｎｄａｇｅ）");
		set("value",0);
	}
	set_amount(5);
}

void init()
{
	add_action("do_bandage", "bandage");
}

int do_bandage(string arg)
{
	object ob,*mem;

	if (this_player()->is_busy())
		return notify_fail("你现在正忙。\n");

	if( !arg ) ob = this_player();
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !ob->is_character() )
			return notify_fail("你要替谁裹伤？\n");
	}

/*	if( this_player()->is_fighting()
	||	ob->is_fighting() )
		return notify_fail("战斗中不能裹伤。\n");*/
	
	if (ob!= this_player()) {
		mem = this_player()->query_team();
		if (!pointerp(mem) || member_array(ob,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人裹伤。\n");
	}
			 
	if( (int)ob->query("eff_kee") == (int)ob->query("max_kee") )
		return notify_fail( (ob==this_player()? "你" : ob->name())+ "并没有受到任何外伤。\n");

	if( ob->query_condition("bandaged"))
		return notify_fail( (ob==this_player()? "你" : ob->name())+ "身上的伤已经裹著其他东西了。\n");

	if( ob==this_player() )
		message_vision("$N用" + name() + "替自己裹伤。\n", this_player());
	else
		message_vision("$N用" + name() + "替$n裹伤。\n", this_player(), ob);

	ob->set_temp("pfm/bandaged", this_player()->query_skill("manjianghong",1));
	ob->apply_condition("bandaged", 10);	
	if (ob->is_fighting())
		ob->perform_busy(1);
	add_amount(-1);
	return 1;
}
