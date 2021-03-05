#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
	string * msg = ({
	CYN"笼雾轻纱",RED"霞云彩绫",HIR"真虹纱羽",HIB"疏雨云河",HIR BLK"坠月玄纱",HIW"冰影织衣",MAG"紫蝶纱羽",HIR"红莲霓裳",WHT"素丝羽衣",BLU"圣灵法袍",HIB"明蓝夜雨",HIW"飘渺银带",HIG"映碧湖云"
	});
	set_name(msg[random(sizeof(msg))]+NOR, ({ "surcoat" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "件");
        set("female_only",1);
		set("long","一件绡纱长裙，轻柔有如无物。\n");
	}
	::init_surcoat();
}


int init()
{
	set("armor_worn","披着");
}
