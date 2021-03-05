#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIY"通天水冠"NOR, ({ "hat" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "皇帝的龙冠，用细如发丝的金丝编织而成的，上饰造型生动的二龙戏水。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 100);
		set("thief_obj", 1);
	}
	::init_head();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
