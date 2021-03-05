#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
    set_name(CYN"淡青银针"NOR, ({ "cyan needle","needle" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
        set("long", "一根细如发丝，长比小指的淡青色银针，针尖沾染了褐红色的血迹。\n");
		set("value", 1000);
		set("material", "silver");
	}
    ::init_dagger(20);
}
