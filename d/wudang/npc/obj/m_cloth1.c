#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
    	set_name(HIW"江牙海水白蟒袍"NOR, ({ "whitecloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一套官服，穿上后让人觉的亦狂亦侠亦温文。\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
