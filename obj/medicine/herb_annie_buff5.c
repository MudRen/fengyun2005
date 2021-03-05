// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("双彩霓石",({"nishi"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一颗有着碧彤双色的半透明小石，传闻是娥眉佛光经年照耀下的产物。\n");
	    set("unit","颗");
	    set("base_unit","颗");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",360000);
	}
	set_amount(1);
}
