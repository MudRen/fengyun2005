// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("断剑", ({ "guo sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄毫不起眼的铁剑，剑柄上浅浅地刻着几个字--
   ＂剑在人在，剑亡人亡＂ - 郭。\n");
		set("value", 400);
		set("material", "steel");
	}
	::init_sword(10);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}
