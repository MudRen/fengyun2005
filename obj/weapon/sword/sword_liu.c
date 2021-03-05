#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( CYN"青冥劍"NOR, ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "削鐵如泥的寶劍, 劍刃上有著奇異的花紋. 看著它心頭泛起了一陣寒意。\n");
		set("value", 3000);
		set("material", "steel");
		set("rigidity", 200);
		set("level_required",100);
		set("wield_msg", "$N从宝玉剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的宝玉剑鞘。\n");
	}
	::init_sword(70);
}

