// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name(CYN"青狼牙爪"NOR, ({ "wolf claw","claw" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一对用青狼之牙做成的爪子。\n");
		set("material", "bone");
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(5);	
}

