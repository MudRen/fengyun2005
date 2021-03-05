// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("十圣金丹",({"jindan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","据说是扁鹊流传下的古方所制，能让枯木回春，效用非凡。\n");
	    set("unit","粒");
	    set("base_unit","粒");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",120000);
	}
	set_amount(1);
}
