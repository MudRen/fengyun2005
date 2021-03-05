#include <armor.h>
inherit MASK;

void create()
{
	set_name("鲛绡面纱", ({ "jiaoxiao" , "jiaoxiao miansha", "miansha"}) );
	set_weight(4);
	if(clonep()) 
	    set_default_object(__FILE__);
	else {
    	set("unit", "块");
    	set("long", "一条盈洁如水的面巾，据传远古是鲛人所织，戴上它就能像鱼儿一样在海中随意遨游。\n");
    	set("material", "cloth");
    	set("避水", 1);
    	set("value", 300);
        set("armor_prop/long", ({"脸上蒙着一层如烟似水的面纱，看不清真正面目。\n"}) );
        set("armor_prop/use_under_water", 100);
    }
    ::init_mask();
}



