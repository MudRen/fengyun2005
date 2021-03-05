#include <weapon.h>
inherit SWORD;

void create() {
	set_name("重剑", ({ "heavy sword","sword" }) );
	set_weight(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长剑，只是份量重了许多。\n");
		set("rigidity", 300000); 
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(35);
}
