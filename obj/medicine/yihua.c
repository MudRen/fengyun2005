inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    	set_name(CYN"无名花"NOR , ({ "flower" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", CYN"一朵不知名的小花，花呈淡淡的蓝色，清香扑鼻。\n"NOR);
        	set("unit", "朵");
        	set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
	mapping buff;
	object me = this_player();
	int amount;
	string msg;
	
	if (ANNIE_D->check_buff(me,"gks"))	// it won't show up..just eat it.
		return notify_fail("你已经服用过类似的丹药了。\n"); 
					
	msg = HIR "$N的全身映出一阵红光！！\n"NOR;
	
	amount = 100;
	buff =
		([
			"caster": me,
			"who":   me,
			"type": "gks",
			"att":	"bless",
			"name":	"无名花",
			"buff1": "kee",
			"buff1_c":1000,
			"time":  20 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
		
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}