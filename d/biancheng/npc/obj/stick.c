#include <weapon.h>

inherit STAFF;

void create()
{
    	set_name("拐棍", ({"stick"}) );
    	set_weight(1000);
    	if( clonep() )
             set_default_object(__FILE__);
    	else {
          	set("unit", "根");
          	set("long", "一根三尺长的拐棍。\n");
          	set("value", 50);
          	set("material", "wood");
          	set("wield_msg", "$N拿起一把$n握在手中。\n");
          	set("unwield_msg", "$N放下手中的$n。\n");
         } 
   	::init_staff(10);

}
