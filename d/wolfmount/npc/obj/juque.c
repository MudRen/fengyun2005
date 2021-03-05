// Tie@fengyun
#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("巨阙", ({ "ancient dagger","dagger" }) );
        set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	        set("long", "春秋时铸剑大师欧冶子炼铸的三大二小五把宝剑之一，小巧玲珑，切金断玉。\n");
	        set("value", 500);
		set("material", "steel");
	        set("wield_msg", "犹如一道闪电划破长空，一把寒光闪闪的$n已赫然擎在$N手中。\n");
	        set("unwield_msg", "$N小心翼翼将手中的$n插入皮鞘。\n");
	}
    	
    	::init_dagger(95);
}
