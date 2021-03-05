// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("银戈草",({"yinge"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一棵叶茎浅白的小草，传说能上通灵阙，下破三元。\n");
	    set("unit","棵");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",10000);
	}
	set_amount(1);
}
