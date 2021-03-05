#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("寒泉凝乳",({"frozen elixir", "elixir"}));
  	set("long", "一滴乳白色的汁液，虽小，散发着逼人的寒气。\n");
  	set("base_value",5000);
  	set("unit","些");
  	set("base_unit","滴");
  	set("base_weight",50);
  	set("desc_ext","服用（drink frozen elixir）");
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({ "drink" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "frozen elixir")
		return 0;
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
  	
  	message_vision(CYN"$N饮下一滴"+name()+"。\n"NOR,me);
	if( ANNIE_D->check_buff(me,"freeze")) 
	{
		add_amount(-1);
		return 1;
	}
		buff =
		([
			"caster":me,
			"who":me,
			"type":"freeze",
			"att":"curse",
			"name":"药物：寒泉凝乳",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <冻僵中>"NOR,
			"time":20+random(20),
			"buff_msg":HIW"$N打了一个冷颤，顿时动弹不得！\n"NOR,
			"disa_msg":HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
  	add_amount(-1);
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
