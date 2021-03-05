// sword.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(  "咒剑王夫" , ({ "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
"这是一把桃木雕成的古剑，闻起来有一股香味，剑身刻著许多你从未见过的咒
文，只有剑柄部份有两个依稀可以辨认的篆字：「 王 夫 」。不过，从手工来
看，这显然只是一把仿照的模型。
\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        	set("weapon_prop/spirituality", 3);
        }
	 
        ::init_sword(14);
}
