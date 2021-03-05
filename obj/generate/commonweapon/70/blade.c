#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create() {
	set_name(HIB"虎啸穹苍"NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "iron");
//		set("long", "这是一寻常的单刀，份量大约六、七斤重。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	::init_blade(70);
}
