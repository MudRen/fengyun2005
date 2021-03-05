// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("丈八蛇矛", ({ "zhang spear", "spear" }) );
	set_weight(10000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "长一丈八尺，四尺枪头如蛇身蜿蜒。暗红的枪缨映着黝黑的枪身，
虽是一件无知之物，却也凛凛生威。");
		set("value", 800);
		set("rigidity", 2000);
		set("material", "steel");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_spear(25);
}
