
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(RED"金璐红袄"NOR, ({ "red coat","coat" }) );
	set_weight(3000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 10);
        set("armor_prop/armor", 6);
		set("long", "一件红色衣服，发出一种红得耀眼，红得令人心跳的光。\n");
          set("female_only", 1);
	}
	::init_cloth();
}
