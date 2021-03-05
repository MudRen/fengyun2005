
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("地耳草",({"dier", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","簇");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","kee/10");
	    set("type","cure");
	    set("base_value",800);
	    set("level",120);
	    set("effect",2000);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}


