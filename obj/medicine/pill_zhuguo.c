inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"朱果"NOR , ({ "zhuguo" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", RED"朱红色的野果，暗香扑鼻，据说服食以后会暂时提高气血！\n"NOR);
        	set("unit", "个");
        	set("lore",1);
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
					
	msg = HIR "$N只觉腹中一股清雅的香气。暖洋洋的十分舒服。\n"NOR;
	
	buff =
		([
			"caster": me,
			"who":   me,
			"type": "gks",
			"att":	"bless",
			"name":	"朱果",
			"buff1": "kee",
			"buff1_c":1000,
			"time":  1800 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
		
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}
