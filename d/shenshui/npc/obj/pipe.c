#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIM "心事" NOR, ({ "romance" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
				set("no_drop",1);
				set("long", "
这东西是水天姬从黄金宫里偷出来的，原来叫做蚀心化骨焦烂骸丧门火，
水天姬嫌它又长又不好听，就改个花俏的名字叫“心事”，女孩子的心事，
专门给刚入门经验不足的弟子防身用（ｓｈｏｏｔ）。每筒可以使用数次，
用完后唯有水天姬才能重新将机关复原。别看它貌不惊人，当年江湖第一
少年高手公孙红就差点丧生在心事上。
此暗器的杀伤力与姹女神功相关。
\n");
                set("material", "silver");
                set("ss_shui",1);
                set("ammo", 10);
        }
        ::init_item();
}

void init()
{
		add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
		object ob, target, me;
		string msg;	
		int damage;
		
		if (!arg) return notify_fail("你要打谁？\n");
		if (query("ammo")<1) 
				return notify_fail(this_object()->name()+"已经用完了。\n");
	
		me=this_player();
    	
    	if (me->query("timer/ss_heart") + 300 > time())
    			return notify_fail(this_object()->name()+"刚刚使用过，机关正在回复中。\n");
    		
    	if( environment(me)->query("no_fight")
    		 || environment(me)->query("no_magic") 
    		 || environment(me)->query("no_spells"))
    		 return notify_fail("在这不可偷袭！\n");
    	
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
    		return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    	
    	if (userp(me) && me!= ob)
		if (!COMBAT_D->legitimate_kill(me, ob)) {
			if (stringp(ob->query("NO_KILL")))
				return notify_fail(ob->query("NO_KILL"));
			if (stringp(ob->query("NO_PK")))
				return notify_fail(ob->query("NO_PK"));	
			else 
				return notify_fail("你无法攻击此人。\n");
		}
		
		if (me->is_busy())
				return notify_fail("你现在正忙！\n");
	
		if (!me->is_fighting(ob))
				return notify_fail( this_object()->name()+ "是用来防身的，可不是去招惹他人。\n");
			
    	if (ob == me)
    		return notify_fail("小小年纪就自己找死？\n");
    	
    	damage = 100 + me->query_skill("nine-moon-spirit",1)* 5; 
    	if (damage > 600) damage = 600;	// ppl would de-level :D    	
    	
    	message_vision(HIW"\n$N"HIW"狡黠的一笑，衣袖飘飘轻轻挥起，却突然有一条银线，飞射而出。。。\n"NOR,me,ob);
    	me->set("timer/ss_heart",time());
    	
    	target = ob;
    	
    	if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw/weiwoduzun","unarmed", 500, 10))
    	{
    	   	msg = WHT"$n猝不及防，惨叫一声被射了个正着！\n" NOR;
        	damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
        	target->receive_wound("kee", damage, me);
        	message_vision(msg, me, target);
        	COMBAT_D->report_status(target,0);
    	}
    	else {
    		msg = CYN"$n把头一缩，哧的一声微响，青蓝色的火苗从发间闪过！\n";
			message_vision(msg, me, target);
		}
    		
    	ob->kill_ob(me); 
	   	add("ammo",-1-random(2));
    	me->perform_busy(3);
    	return 1;
}
