#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("鲨鱼皮", ({ "shark skin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("material", "cloth");
	set("no_stack",1);
		set("for_create_cloth",1);
		set("armor_prop/armor", 5);
		set("long","一块坚韧无比的鲨鱼皮。\n");
		set("max_enchant",7);
		set("base_armor",50);
		set("value",0);
	}
	::init_cloth();
}
