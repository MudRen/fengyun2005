#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("草帽", ({ "hat" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
        set("long", "一顶大草帽，多见于西南地区。\n");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
    ::init_head();
}
