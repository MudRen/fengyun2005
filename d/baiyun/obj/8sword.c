#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	int i;
   string *order=({"掩日", "断水", "转魄", "悬翦",
"惊鲵","灭魂","却邪","真刚"});
	i=random(8);

    set_name("断掉的"+order[i], ({ "broken sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit", "把");
	set("long", "一把断掉的"+order[i]+"，据说是越王八剑之一，据说这八剑乃是远古时由一块天外陨石
分为八块而铸成，传说若是八块集齐，交于天下最巧手之人，则有惊世神兵现世！\nu");
	set("value", 100);
	set("no_reset",1);
	set("material", "steel");
	}

    ::init_sword(1);
}

