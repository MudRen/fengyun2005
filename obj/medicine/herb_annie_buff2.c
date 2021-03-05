// annie 07.04.2003

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name("莲花瓣",({"lianhua"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一片白莲花的花瓣，传闻中是西方秘法圣药。\n");
	    set("unit","瓣");
	    set("base_unit","瓣");
	    set("base_weight",30);
	    set("type","medicine");
	    set("is_drug","1");
	    set("base_value",40000);
	}
	set_amount(1);
}
