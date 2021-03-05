#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIW"天狼鞭"NOR, ({ "wolf whip","whip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 15000);
                set("long", "一条四丈有奇的银鞭。鞭身每过数尺就有十多只明晃晃的尖利倒钩，鞭头上是
一个栩栩如生的狼头。\n");
                set("material", "skin");
		set("weapon_prop/courage",5);
		set("rigidity", 10000);
		set("experience",5000000);
        	set("wield_msg", "$N左手在腰里一拉一抖，突然飞出烂银也似的一条长蛇来握在手中。\n");
        	set("unwield_msg", "$N将手中的$n束回腰间。\n");
        }

        ::init_whip(140);
}


int query_autoload() { return 1; }