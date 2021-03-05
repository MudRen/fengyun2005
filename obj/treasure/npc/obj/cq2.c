#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIW "苍穹神剑"NOR, ({ "cang qiong" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄没有剑头的长剑\n");
		set("value", 1);
		set("rigidity",2000);	
		set("material", "steel");

			set("weapon_material",1);
			set("material_level",110);
			set("desc_ext","祭炼武器(110)");
    }
	::init_sword(10);
}

