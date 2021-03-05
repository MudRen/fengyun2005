#include <armor.h>
#include <ansi.h>
inherit CLOTH;


void create()
{
	set_name(YEL"黄色的长衫"NOR, ({ "yellow suit", "suit" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件黄色的布衫，衫角长及脚面。\n");
		set("unit", "件");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

