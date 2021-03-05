#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
//霞雲彩綾 真虹紗羽 疏雨云河 坠月玄纱
void create()
{
	set_name(CYN"明蓝夜雨"NOR, ({ "longskirt" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "件");
        set("female_only",1);
		set("long","一件水蓝色的绡纱长裙，轻柔有如无物。\n");
	}
	::init_surcoat();
}


int init()
{
//	::init();
	set("armor_worn","外笼");
}
