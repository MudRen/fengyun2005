// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit DAGGER;
void create()
{
	string *order=({"红", "绿", "黄", "白","黑"});
        set_name((order[random(5)]) +"色的绣花针", ({ "needle", "flower needle"}) );
    set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
        set("long", "一根细长的银针，轻飘飘地似乎要随风而去。\n");
        set("value", 500);
		set("material", "steel");
	}
    ::init_dagger(20);
	set("wield_msg", "$N从怀中摸出一支$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");
}
