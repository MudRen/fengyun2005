#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name( "尚方宝剑", ({ "royal sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把古色古香的宝剑，一看就不是凡品，上面刻着“钦赐－殷正廉”几个字。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
		set("shangfang",1);
		set("thief_obj",1);
	}
    ::init_sword(15);
}
