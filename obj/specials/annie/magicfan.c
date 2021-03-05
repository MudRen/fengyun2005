#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(HIG"灵虚扇"NOR, ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当精致的摺扇，扇面上画着半筝雪关图。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n展开握在手中扇了两下。\n");
		set("unwield_msg", "$N将手中的$n合起收入袖中。\n");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
	}
	::init_dagger(1);
}


void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object me=this_player();
	mapping buff;
	if (!arg || present(arg,me) != this_object())
		return 0;
	if (me->query_weapon() != this_object())
		return 0;
	if( ANNIE_D->check_buff(me,"fastrecover")) 
		return notify_fail("你现在正在施展类似的能力。\n");
	buff =
	([
		"caster":me,
		"who":me,
		"type":"fastrecover",
		"att":"bless",
		"buff1":"annie/fast_heal",
		"buff1_c":15,
		"name":"灵虚扇·神气流转",
		"time":300,
		"buff_msg":"$N展开"HIG"灵虚扇"NOR"，一阵淡淡的栀子幽香弥散开来．．\n",
	]);


	ANNIE_D->buffup(buff);

	me->perform_busy(2);
	return 1;
}




