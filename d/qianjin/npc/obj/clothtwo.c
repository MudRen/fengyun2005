// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("舞蝶彩衫", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件五彩斑阑的舞蝶彩衫\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
