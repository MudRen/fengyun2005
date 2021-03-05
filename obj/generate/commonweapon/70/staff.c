#include <ansi.h>


#include <weapon.h>
inherit STAFF;

void create() {
	set_name(YEL"一渡迷航"NOR, ({ "staff" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
//		set("long", "这是一把看起相当普通的木棍");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "iron");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_staff(70);
}
