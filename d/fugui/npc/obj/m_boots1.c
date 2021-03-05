// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name(WHT"皂底蟒靴"NOR, ({ "whiteboots" }) );
      set_weight(900);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("long", "这鞋方便快捷，来去如风\n");
		set("value", 1000);
	}
	::init_boots();
}
