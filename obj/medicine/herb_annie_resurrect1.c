// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("符水",({"holywater"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一碗巫医用以救病的符咒之水，据称可以起死回生。\n");
	    set("unit","碗");
	    set("base_unit","碗");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",20000);
	}
	set_amount(1);
}
