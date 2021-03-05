#include <ansi.h>
#include <armor.h>
inherit BOOTS;
//霞雲彩綾 真虹紗羽 疏雨云河 坠月玄纱
void create()
{
	set_name(WHT"素白缎面小鞋"NOR, ({ "shoes" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "件");
        set("female_only",1);
	}
	::init_boots();
}

