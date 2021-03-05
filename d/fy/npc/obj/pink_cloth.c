// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIM"粉红绸衫"NOR, ({ "pink cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件粉红色的绸衫上面绣著几只黄鹊，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}

