// cloth.c
//

#include <armor.h>

inherit HEAD;
#include <ansi.h>
void create()
{
    set_name(HIW"哈达"NOR, ({ "hada" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");

        set("long","一根洁白如圣母之雪的哈达，是藏人赠送给最尊贵的客人的礼物。\n");
		set("material", "cloth");
		set("value", 7);
		set("armor_prop/armor", 1);
	}
	::init_head();
}
