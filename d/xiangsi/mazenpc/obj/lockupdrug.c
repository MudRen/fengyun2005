#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("石松",({"drug"}));
  	set("long", "一块看不出质地的灰色物品。\n");
  	set("base_value",3000);
  	set("unit","些");
  	set("base_unit","块");
  	set("base_weight",50);
  	set("volumn",1);
  	set_amount(8);
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
  	message_vision(CYN"$N将一块"+name()+"塞进嘴里。\n"NOR,me);
	if(!ANNIE_D->check_buff(me,"lockup")) 
	{
		add_amount(-1);
		return 1;
	}
	ANNIE_D->debuff(me,"lockup");
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
