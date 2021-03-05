// 返璞归真，武当剑道之极致。

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#define TYPE_PERFORM	3

void create() {
	set_name("长剑", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把很普通的长剑，似乎一点也不起眼。\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("unwield_msg", "$N手中的$n一闪而逝。\n");
		set("wield_msg", "$N的手腕一抖，握住一把长剑。\n");
	}
	::init_sword(130);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object spirit;
	string msg;
	if (random(4))
	{
		msg =  HIC "$N手中"+name()+ HIC "忽然青芒疾闪，剑气暴涨，从剑尖射向$n。\n"NOR;
		
	}
    	return 0;
}
