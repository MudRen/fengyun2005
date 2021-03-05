#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("银戟", ({ "spear" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "
这是吕凤先视如生命的银戟，但枪尖枪身都染满了吕凤先的鲜血，奇怪的是，
鲜血泛着一种妖异的绿色，摇曳闪烁，还是拿回给铁传甲仔细查看查看吧。\n");
		set("value", 1);
		set("lu_spear",1);
		set("material", "steel");
		set("nodrop_weapon",1);
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入地下。\n");
	}
	::init_spear(10);
}
