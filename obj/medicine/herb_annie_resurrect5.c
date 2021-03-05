// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("辉月魂石",({"huiyue"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一颗银白色的小石，凝聚了千年月照的精华。\n");
	    set("unit","颗");
	    set("base_unit","颗");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",720000);
	}
	set_amount(1);
}
