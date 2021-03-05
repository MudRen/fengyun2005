#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("玄真剑", ({ "myst sword","sword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄缀着淡黄流苏，映日光寒的长剑。\n");
  				set("no_stack",1);
				set("no_drop",1);
              set("value", 0);
                set("material", "steel");
        }
        ::init_sword(73);
}
