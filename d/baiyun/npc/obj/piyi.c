#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIY"棕色皮衣"NOR, ({ "brown cloth","cloth" }) );
	set_weight(13000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("long","一件棕色的皮衣，显然是久历风霜，布满了灰土。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	    set("value",20);

	}
	::init_cloth();
}

