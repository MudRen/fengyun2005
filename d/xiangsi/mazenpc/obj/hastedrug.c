#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("轻身顺气散",({"haste drug"}));
  	set("long", "一包淡黄色的粉末，据说服用后可以健步如飞，身轻如燕。\n");
  	set("base_value",1000);
  	set("unit","堆");
  	set("base_unit","包");
  	set("base_weight",500);
  	set("desc_ext","服用（eat haste drug）");
  	set("volumn",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({"eat" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "haste drug")
		return 0;
		
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
  	
  	message_vision(CYN"$N服下一包"+name()+"。\n"NOR,me);
	if( ANNIE_D->check_buff(me,"haste")) 
	{
		add_amount(-1);
		return 1;
	}

	buff =
	([
		"caster":me,
		"who":me,
		"type":"haste",
		"att":"bless",
		"name":"药物：轻身顺气散",
		"buff1":"apply/haste",
		"buff1_c":15,
		"time":30+random(90),
		"buff_msg":CYN"$N脸色忽青忽白，出手速度陡而加快。\n"NOR,
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
