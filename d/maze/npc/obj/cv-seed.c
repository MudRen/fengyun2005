#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"灵符火种"NOR, ({"seed"}) );
	set_weight(5);
	set("long",
		"这是一颗灵符火种，隐隐可以看到灵符包裹着的三味真火之种在灵符中摇曳着，燃烧着。（throw）\n");
	set("unit", "枚");
        set("value", 0);
}
