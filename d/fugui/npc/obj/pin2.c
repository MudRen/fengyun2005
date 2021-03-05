
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
    set_name(HIB"比翼双飞钗"NOR, ({ "lovepin"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根名贵的比翼双飞钗，乃定情之物，悠久流传。\n");
		set("unit", "根");
		set("value", 500000);
		set("armor_prop/armor", 1);
		set("wear_msg", "$N轻轻地把一根$n插在头上。\n");
		set("unwield_msg", "$N轻轻地把$n除了下来。\n");
		set("female_only", 1);
        }
        ::init_head();
}

