#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED"夕影刀"NOR, ({ "cyin blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "flex");	// :>>....flex blade
		set("no_get",1);
	}
	::init_blade(77);
}

int query_autoload() { return 1; }
/*
int protection() {
	object me = environment(this_object());
	int result;

	if (!me)
		return 0;
	if (me->query("kee") < 1)
		return 0;
	
	result = random(4) ? 1 : 0;
	set("protected", result);
	return result;
}

string protection_msg() {
	object me = environment(this_object());

	if (!me)
		return "";
	if (me->query("kee") < 1)
		return "";
	
	return query("protected") ? HIR BLK"夕影刀映出一片朦朦胧胧的淡霞泠光，笼罩在"+me->name()+HIR BLK"周围，护住"+me->name()+HIR BLK"。\n$N"HIR BLK"方近"+me->name()+HIR BLK"身边，就被光华迫退。\n"NOR
			: "";
}
*/