
#include <weapon.h>

inherit FORK;

void create()
{
   set_name("钉耙", ({ "dingpa", "ding pa" }) );
	set_weight(120000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
         set("long", "一柄九齿钉耙，农人常用的家什。\n");
		set("value", 800);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从腰间拔出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n扛在肩上。\n");
	}
    ::init_fork(10);
}
