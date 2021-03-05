
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name(MAG"朝阳"NOR"五凤挂珠钗", ({ "phenixpin"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根名贵的"MAG"朝阳"NOR"五凤挂珠钗富贵深沉，系出名家之手\n");
		set("unit", "根");
		set("value", 500000);
		set("armor_prop/armor", 1);
		set("wear_msg", "$N轻轻地把一根$n插在头上。\n");
		set("unwield_msg", "$N轻轻地把$n除了下来。\n");
		set("female_only", 1);
        }
        ::init_head();
}

