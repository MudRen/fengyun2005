#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIG"碧玉胡刀"NOR, ({ "jadeblade" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把弯如月牙儿，镶满碧玉的胡刀。");
                set("value", 900);
		set("rigidity", 200);
                set("material", "steel");
	        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
	        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(15);

}

