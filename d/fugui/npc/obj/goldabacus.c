#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
#include <command.h>

void create()
{
        set_name(HIY"金算盘"NOR, ({ "abacus","gold abacus" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","一块金灿灿的算盘，掂在手里沉甸甸的。\n");
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "$N「啪」地一声拿出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n拨弄了几下，挂回腰后。\n");
        }
        ::init_hammer(10);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	dam = (int) me->query("force_factor");  //*2; //add by ldb *2 便于杀黑袍公 
	victim->receive_damage("gin",dam,me);

	return HIR"金算盘哗哗作响，$n心烦意乱，无心恋战。\n"NOR;
}

