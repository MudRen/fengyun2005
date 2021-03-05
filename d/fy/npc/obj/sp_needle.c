// annie

#include <weapon.h>
inherit DAGGER;
void create()
{
    set_name("青色的细针", ({ "needle", "long needle"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一根细长的银针，上面刻着＂金木水火土＂几个蝇头小字\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N从怀中摸出一支$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n藏入怀中。\n");
		set("no_give",1);
	}
	::init_dagger(10);
}
