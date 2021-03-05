#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(RED"屠刀"NOR, ({ "butcher knife","knife" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "八月初八手中的屠刀，屠杀了无数人畜，刃口上虽然磕了\n不少口子，但依旧锋利无比。\n");
                set("value", 500);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(20);
}
