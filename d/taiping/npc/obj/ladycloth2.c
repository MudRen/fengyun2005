#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(RED"大红洋缎窄袄"NOR, ({ "ao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件大红洋缎窄袄。\n");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value",100);
	}
	::init_cloth();
}
