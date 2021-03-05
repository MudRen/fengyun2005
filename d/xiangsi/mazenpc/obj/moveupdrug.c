#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("寒泉凝乳",({"drug"}));
  	set("long", "一滴乳白色的汁液。\n");
  	set("base_value",5000);
  	set("unit","些");
  	set("base_unit","滴");
  	set("base_weight",50);
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({ "use","eat" }));
}

int do_cure()
{
	object me;
	mapping buff;
	me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
  	message_vision(CYN"$N饮下一滴"+name()+"。\n"NOR,me);
	if( ANNIE_D->check_buff(me,"moveup")) 
	{
		add_amount(-1);
		return 1;
	}

	buff =
	([
		"caster":me,
		"who":me,
		"type":"moveup",
		"att":"bless",
		"name":"药物：寒泉凝乳",
		"buff1":"apply/agility",
		"buff1_c":3,
		"time":600,
		"buff_msg":CYN"$N觉得心底有一丝暖流流过．．\n"NOR,
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
