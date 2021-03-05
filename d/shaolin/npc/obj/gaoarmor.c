// ; annie 07.2003
// dancing_faery@hotmail.com

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(YEL"雷泽密甲"NOR, ({ "jade armor" }) );
	set_weight(200000);	// 50 str 20%.
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "jade");
		set("armor_prop/armor", 150);
		set("value",400);	// robot gao? hmm....恐怕不大容易吧...
	}
	::init_cloth();
}
