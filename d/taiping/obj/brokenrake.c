#include <weapon.h>
inherit FORK;

void create()
{
   	set_name("缺齿的钉耙", ({ "broken rake","rake" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
         	set("long", "一柄九齿钉耙，好几根齿已经残缺不全。\n");
		set("value", 800);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从腰间拔出一柄$n握在手中。\n");
        	set("unwield_msg", "$N将手中的$n扛在肩上。\n");
	}
    ::init_fork(10);
}
