// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
    set_name(HIR"红腰带"NOR, ({ "red girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("long", "这是一条鲜红如血的腰带。\n");
		set("value", 700);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_waist();
}
