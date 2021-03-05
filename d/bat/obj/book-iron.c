// book3.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("铁手掌", ({ "iron hand", "hand"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long","蝙蝠岛攻防篇\n"
			"这是一块铁手掌，上面凹凹凸凸刻满了人形搏击的场面。\n");
		set("value", 500);
		set("material", "steel");
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"sen_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	39	// the maximum level you can learn
		]) );
	}
	::init_hands();
}

