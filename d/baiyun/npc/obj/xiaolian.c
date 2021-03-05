// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIY"宵练"NOR, ({ "xiaolian sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "殷三名剑之一，剑身亮如日光，可见其影，刀刃却毫无发光，但在月\n光下看却寒气逼人，剑身反而不清。被此剑杀者，毫无痛楚之感，但此剑却滴血不沾。\n又有一名“脊练”。\n");     
        set("value", 600);
		set("material", "steel");
	}
    ::init_sword(10);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}
