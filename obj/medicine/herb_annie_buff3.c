// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("白露水",({"bailu"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一滴清亮透明的露珠，据说是在白露那天收集所得。\n");
	    set("unit","滴");
	    set("base_unit","滴");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",60000);
	}
	set_amount(1);
}
