#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(WHT"纱袍"NOR, ({ "ghost clothes","clothes" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","半透明的纱袍，死一般的颜色，死一般的气息。\n");
		set("material", "cloth");
		set("armor_prop/armor", 0);
	}
	::init_cloth();
}
