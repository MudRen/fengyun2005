inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"还魂草"NOR,({"huanhun grass","grass"}));
	set("long", HIG
		"这是一跟用来根除狼山迷魂草毒性的药草．\n只要把它交给中毒者服下就可根除迷魂草药性．\n"NOR);
	set("value",1);
	set("unit","棵");
 	::init_item();
}
