inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"红玫瑰豆沙月饼"NOR , ({ "mooncake" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", YEL"八月十五日谓之中秋，民间以月饼相遗，取团圆之意。\n"NOR);
        	set("unit", "个");
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
	
	if (ANNIE_D->check_buff(me,"gks"))	// it won't show up..just eat it.
		return notify_fail("美味依存。\n"); 
					
	msg = HIY "$N哼着小曲吃月饼，中秋夜，皓月当空，人们在品茶赏月的同时，总会有几首关于明月的歌曲在心头回荡。\n"NOR;
	
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
		
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}
