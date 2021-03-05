// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(HIG"风"MAG"雷"NOR, ({ "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄毫不起眼的短剑。\n");
		set("material", "bronze");
		set("no_get",1);
		set("nodrop_weapon",1);
	}
	::init_sword(120);	
}

int init()
{
	set("weapon_wielded","提");
}

