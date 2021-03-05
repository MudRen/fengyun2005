#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("固本培元丹",({"antibuff drug"}));
  	set("long", "一包淡蓝色的粉末，据说服用后可不受外界干扰影响。
（抵抗stat中可显示状态的影响）\n");
  	set("base_value",500);
  	set("desc_ext", "服用（eat antibuff drug）");
  	set("unit","堆");
  	set("base_unit","包");
  	set("base_weight",500);
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
	
	if (arg != "antibuff drug")
		return 0;
		
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
  	message_vision(CYN"$N服下一包"+name()+"。\n"NOR,me);
	if( ANNIE_D->check_buff(me,"blocked")) 
	{
		add_amount(-1);
		return 1;
	}
	buff =
		([
			"caster":me,
			"who":me,
			"type":"blocked",
			"att":"bless",
			"name":"药物：固本培元丹",
			"time": 10+random(10),
			"buff_msg":CYN"$N顿觉灵智清醒，真气充盈。\n"NOR,
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
