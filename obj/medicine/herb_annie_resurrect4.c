// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("流光镜玉",({"jingyu"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","极其少见的玉石，映照间清晰如镜，辉华流光。\n");
	    set("unit","块");
	    set("base_unit","块");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",280000);
	}
	set_amount(1);
}
