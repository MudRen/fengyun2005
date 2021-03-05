#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(CYN"江南织造"NOR, ({ "skirt"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value",4500);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 60);
		set("armor_prop/intelligence", -10);
		set("armor_prop/max_gin", 200);
		set("armor_prop/max_kee", 200);
		set("armor_prop/max_sen", 200);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}


int init()
{
	if (environment())
		if (userp(environment()))
			set("value",0);
}
// 凝輕·dancing_faery@hotmail.com

