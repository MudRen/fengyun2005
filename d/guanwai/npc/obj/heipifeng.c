#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(BLK"黑披风"NOR, ({ "black cloak","cloak" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
        set("long", "一件漆黑的披风，迎着风猎猎作响。\n");
        set("armor_prop/armor", 5);
        set("value", 3);
        set("wear_msg", "$N迎风而立，哗啦啦一抖，披上一件$n，猎猎作响。\n");
	}
	::init_cloth();
}
