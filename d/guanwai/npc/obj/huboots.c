// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
          set_name("喀巴沙" , ({ "hu boots","boots" }) );
      set_weight(100);
         if( clonep() )
      set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
        set("long", "藏人们中穿的最名贵的一种皮靴，式样奇特，手工精致。\n");
        set("value", 1000);
        set("armor_prop/armor", 5 );
	}
	::init_boots();
}
