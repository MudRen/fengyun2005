#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"摧肝花"NOR, ({"herb"}) );
	set("wujian",1);
	set_weight(5);
	set("long", "罕见的药草，剧毒，却是炼制苍生乱解药的药材之一。\n");
	set("unit", "根");
        set("value", 1000);
}
