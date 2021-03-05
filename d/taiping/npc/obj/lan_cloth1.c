#include <armor.h>
inherit CLOTH;
void create()
{
 	set_name("白襟蓝衫", ({ "blue clothes", "clothes" }) );
    	set_weight(100);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
	        set("unit", "件");
	        set("material", "cloth");
	        set("armor_prop/armor", 10);
	    	set("value",4000);
    	}
    ::init_cloth();
}
