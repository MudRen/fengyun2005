#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(HIR"糖葫芦"NOR, ({ "candy"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根看起来又香又甜，裹着一层薄薄发亮焦糖的糖葫芦。\n");
		set("unit", "根");
		set("value", 1500);
		set("food_remaining", 2);
		set("food_supply", 3);
		set("material", "food");
	}
	::init_item();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
