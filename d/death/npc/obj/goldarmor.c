// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
	set_name(HIY"金盔"NOR, ({ "jinkui", "kui" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("material", "gold");
		set("value", 9000);
		set("armor_prop/armor", 10);
	}
	::init_head();
}
