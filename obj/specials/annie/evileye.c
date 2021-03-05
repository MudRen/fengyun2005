#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
	set_name( RED "森罗天眼" NOR, ({ "evil eye" }) );
	set_weight(80);
	if(clonep())
	   set_default_object(__FILE__);
	else{
	set("unit", "个");
	set("long", @LONG
一枚血红的卵石，石中有漆黑的瞳仁，如真正的眼珠一般。
LONG);
	set("material", "silver");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
	}
	::init_item();
}

void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	string where;
	int dp;
	int damage;
	if (!arg) return notify_fail("你要打谁？\n");
	me=this_player();
	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
	return notify_fail("在这不可偷袭！\n");
	ob=present(arg,environment(me));
	if (!objectp(ob) || !living(ob)) 
		return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    	
    if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob))
	{
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}

	if (me->query("timer/annie_shoot") + 2 > time())
		return notify_fail("你失败了。\n");
	
	message_vision(RED"$N祭起森罗天眼，刹时间窜出一道血红的尖芒射向$n！\n"NOR,me,ob);
	ob->receive_damage("kee",13,me); 
	if (ob!=me && !ob->is_fighting(me))	ob->kill_ob(me); 

	if (!random(10))
		me->set("timer/annie_shoot",time());

	return 1;
}


  

