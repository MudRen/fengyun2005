
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
    set_name(HIG"赤金点翠麒麟"NOR, ({ "greenpin"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个名贵的赤金点翠麒麟。典雅高贵，引人遐思\n");
		set("unit", "个");
		set("value", 500000);
		set("armor_prop/armor", 15);
		set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        ::init_head();
}

