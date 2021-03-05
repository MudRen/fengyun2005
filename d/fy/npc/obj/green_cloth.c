// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIG"浅绿小褂"NOR, ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件浅绿色的小褂上面绣著几只黄鹊，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}

