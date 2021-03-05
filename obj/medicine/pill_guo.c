inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("紫菁玉蓉膏" , ({ "potion", "magic potion" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  	set("long", WHT"这是一块有神奇功效的紫膏，可暂时增加200点精力。\n"NOR);
		set("unit", "块");
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
			"name":	"紫菁玉蓉膏",
			"buff1": "gin",
			"buff1_c":200,
			"time":  600 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
		
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}
