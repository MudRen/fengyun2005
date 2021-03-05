// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("玉枢丹",({"yushu"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一粒混天下七种奇药炼制出的珍贵丹丸。\n");
	    set("unit","粒");
	    set("base_unit","粒");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",140000);
	}
	set_amount(1);
}
