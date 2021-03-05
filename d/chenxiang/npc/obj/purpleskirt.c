// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(GRN"素纨长裙"NOR, ({ "greenskirt" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件绿裙似荷叶飘荡，罗袜微尘。\n");
		set("material", "cloth");
        	set("value", 2000);
         	set("armor_prop/armor", 3);
		set("female_only", 1);
	}
	::init_cloth();
}
