#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(CYN"青绫绸裙"NOR, ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 1400);
                set("material", "cloth");
		set("armor_prop/armor", 2);
                set("wear_msg", "$N将$n拿出系在腰上。\n");
                set("female_only",1);
        }
	::init_cloth();
}
