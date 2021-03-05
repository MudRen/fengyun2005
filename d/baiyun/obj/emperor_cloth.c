#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"缂丝十二章衮服"NOR, ({ "emperor cloth","cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "是当今皇上才能穿的龙袍，上衣下裳相连，里外三层，以黄色方目纱为里，
缂丝为面，中间衬层以绢、纱、罗织物杂拼缝制，通体缂制而成。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 100);
		set("thief_obj", 1000);
	}
	::init_cloth();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
