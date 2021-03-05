inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"烤火鸡"NOR , ({ "turkey" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", RED"一整只香气四溢的烤火鸡，看着都口水直流。\n"NOR);
        	set("unit", "只");
        	set("lore",1);
        	set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
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
	
	if (ANNIE_D->check_buff(me,"strup"))	// it won't show up..just eat it.
		return notify_fail("美味依存。\n"); 
					
	msg = HIR "$N顾不得四周的异样眼神，狼吞虎咽的啃了起来。此时此刻遥想远方的亲人能一起分享那该多好。\n"NOR;
/*	
	buff =
		([
			"caster": me,
			"who":   me,
			"type": "gks",
			"att":	"bless",
			"name":	"红玫瑰豆沙月饼",
			"buff1": "kee",
			"buff1_c":1333,
			"buff2": "gin",
			"buff2_c":1888,
			"buff3": "sen",
			"buff3_c":1666, 
			"time":  43200 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
*/		
		buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"strup",
			"att":	"bless",
			"name":	"烤火鸡",
			"buff1":"apply/strength",
			"buff1_c":10,
			"time":  43200 ,
			//"buff_msg":BGRN + WHT"$N凝神聚力，骨骼咯咯作响，身形居然高大了一截！！\n"NOR,
			"buff_msg":msg,
//			"disa_msg": "",
//			"special_func":1,
		]);
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}
