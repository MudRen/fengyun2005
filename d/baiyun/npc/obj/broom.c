// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(YEL"秃了头的扫帚"NOR, ({ "bald broom","broom" }) );
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是一把已经破的连扫帚头上的竹枝全部掉尽，只剩光秃秃的一根扫帚把，但奇\n怪的是这老者还是用这把扫帚扫着剑林，扫地也异常干净，几乎没什么灰尘。\n");
        set("value", 20);
        set("no_get",1);
		set("material", "steel");
	}
    ::init_sword(35);

// These properties are optional, if you don't set them, it will use the
// default values.

    set("wield_msg", "$N拎出一把$n握在手中。\n");
    set("unwield_msg", "$N慢吞吞地手中的$n扛在身后。\n");


}
