#include <armor.h>
inherit MASK;

void create()
{
	set_name("鬼脸面具", ({ "gui mask" , "mask"}) );
	set_weight(4);
	if(clonep()) 
	    set_default_object(__FILE__);
	else {
    	set("unit", "个");
    	set("long", "一个面目狰狞的鬼脸面具。\n");
    	set("material", "cloth");
    	set("value", 30000);
        set("armor_prop/long", ({"脸上戴着一个面目狰狞的鬼脸面具。\n"}) );
    	set("holiday", "鬼节");
    }
    ::init_mask();
}



