// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name(WHT"破旧布靴"NOR, ({ "oldboots" }) );
      set_weight(900);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
        set("long", "一双洗得发白的破旧布靴。\n");
		set("value", 1000);
	}
	::init_boots();
}
