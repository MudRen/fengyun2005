#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(RED"斩马刀"NOR, ({ "zhanma blade","blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "据说这种四尺三寸长的斩马刀来自东瀛，锋利异常。\n");
                set("value", 100);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}
