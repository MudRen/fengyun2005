// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("茵生草",({"yincao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","自石上青苔缝中长出的小草，青翠欲滴，表征生命顽强。\n");
	    set("unit","棵");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",80000);
	}
	set_amount(1);
}
