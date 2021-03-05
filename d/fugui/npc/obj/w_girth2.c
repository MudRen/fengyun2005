// cloth.c
//

#include <armor.h>

inherit WAIST;
#include <ansi.h>
void create()
{
     	set_name(YEL"秋香长穗丝绦"NOR , ({ "fallgirth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");

        set("long","束之纤腰楚楚，回风舞雪。\n");
		set("material", "cloth");
		set("value", 1000);
		set("female_only", 1);
	}
	::init_waist();
}
