// Silencer @ FY4 workgroup. Feb.2005

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "寒冰" NOR, ({ "ice" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "小小的一片薄冰，其薄如纸，却不穿不破。\n");
		set("desc_ext","cure wound");
		set("value", 0);
		set("material", "stone");
	}
	::init_item();
}

void init()
{
	if(environment()==this_player())
		add_action("do_cure","cure");

}

int do_cure(string arg)
{
	object target, me;
	
	me = this_player();
	
	if (arg!= "wound")
		return 0;
	
	if (query("juhan_owner")!=me)	
		return notify_fail("你将寒冰放在伤口上轻轻揉动。。。。太太太冷了！\n");
	
	if (me->is_fighting())
		return notify_fail("战斗中哪有空做这个！\n");
		
	target = me;		
    	if(target->query("eff_kee") == target->query("max_kee"))
		return notify_fail("此寒冰只能用来治疗外伤，对内伤没用！\n");

	if(me->query("marks/legend_juhan")<=0)
	{
		tell_object(me,"寒冰中蕴积的真气已尽，化成清水，无法用来疗伤了。\n");
		destruct(this_object());
		return 1;
	}
	
	target->receive_curing("kee",query("amount"));		
	
	message_vision("$N将一块寒冰放在伤口上轻轻揉动，血淋淋的伤口
居然奇迹般的愈合了许多！！\n", me);
    me->add("marks/legend_juhan",-1);
    	
    if(me->query("marks/legend_juhan")<=0)
	{
		tell_object(me,"寒冰中凝聚的真气散尽，化成了清水。\n");
		destruct(this_object());
		return 1;
	}
	
	return 1;
}
