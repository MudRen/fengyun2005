//	郭嵩阳的断剑---用来提炼玄铁。

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("断剑", ({ "guo sword","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "
这是一柄毫不起眼的铁剑，剑柄上浅浅地刻着几个字--＂剑在人在，剑亡人亡＂，
但是现在剑头已经断折，隐隐透出些银白色的光泽。\n");
		set("value", 400);
		set("guo_sword",1);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(10);

}
