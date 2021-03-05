#include <ansi.h>
#include <armor.h>
inherit NECK;
//霞雲彩綾 真虹紗羽 疏雨云河 坠月玄纱
void create()
{
	set_name("茉莉香串", ({ "jasmine necklace","necklace" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "件");
        set("female_only",1);
	}
	::init_neck();
}

