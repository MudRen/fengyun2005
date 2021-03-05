#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("辟邪玉佩", ({ "jade" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "块");
		set("long", "一块通体洁白的玉佩，据说经过了封法的加持，可以辟邪。\n");
		set("armor_prop/perception",5);
	}
	::init_neck();
}

