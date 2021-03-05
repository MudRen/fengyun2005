inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
    	set_name("浪子", ({ "fea"}) );
    	set("nickname", WHT "千言万词，不如一默"NOR);
    	set("gender", "男性" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 12);
    
    	set("age", 34);
    	set("per", 35);
    	set("int",30);

    	set("attitude","friendly");
    
    	create_family("丐帮", 7, "执杖长老");

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: smart_fight() :),
             }) );

    	set("combat_exp", 10000000);
    
    	set_skill("perception", 200);
    	set_skill("move", 200);
    	set_skill("parry",200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("unarmed",200);
    	set_skill("doggiesteps",170);
    	set_skill("dragonstrike",220);
    	set_skill("huntunforce",150);
    	set_skill("staff",400);
    	set_skill("dagou-stick",220);
    	
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dagou-stick");
    	
    	
    setup();
    carry_object(__DIR__"obj/9bagcloth")->wear();
    carry_object(__DIR__"obj/ego")->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
//	stop_busy();	// lets cheat a bit
//	ccommand("perform banzijue");
	smart_fight();
	return 1;
}

void smart_fight()
{
	object *enemy,target,weapon,me;
	int i,extra, myexp, enemyexp, lvl, mod;
	string msg;

	if (is_busy())
		return;

	me = this_object();
	enemy = me->query_enemy();
	weapon = me->query_temp("weapon");

	if (!weapon)
	{
		message_vision(CYN"\n浪子微微一笑，自玉瓶中抽出一根梅枝。\n\n"NOR,me);
	    carry_object(__DIR__"obj/ego")->wield();
		weapon = me->query_temp("weapon");
	}

	lvl = me->query_skill("dagou-stick",1);

	extra = me->query_skill("staff");	
	myexp = me->query("combat_exp");

	for (i=0;i<sizeof(enemy); i++)
	{
		target = enemy[i];
		enemyexp = target->query("combat_exp");


		if (i == 0)
			msg = YEL"\n$N"YEL"看准$n"YEL"步法的破绽，手中"+ weapon->name() + YEL"如蜻蜓点水般连续击向$n"YEL"下盘。\n" NOR;
		else
			msg = YEL+"\n"+weapon->name()+YEL"落在地上，微微一颠，急颤而起，顺势敲向$n"+YEL"下盘。\n"NOR;

		if (target->query_temp("disable_type") && target->query_temp("is_unconcious"))
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		else 
			message_vision(msg,me,target); 

		if ( myexp/3 + random(myexp/80*extra) > enemyexp)
		{
			msg = HIG"\n只见"+ weapon->name() + HIG"点在地下，轻轻弹起，$n"HIG"似乎是一步赶来凑上去一样。\n"
			HIR+ weapon->name()+HIR"“啪”的一声，狠狠敲在$n"HIR"胫骨上！"NOR"\n\n"
			WHT"随着长声惨叫，$n扑通一下倒在地上！\n\n"NOR;
			target->force_busy(3);
			target->receive_wound("kee", extra+random(extra*2), me);
			call_out("get_up",3, me,target);
			message_vision(msg,me,target);
			COMBAT_D->report_status(target);
			COMBAT_D->win_lose_check(me,target,1);
		}
		else
		{
			me->add_temp("apply/attack", extra/2);
			me->add_temp("apply/damage", extra/2);
			msg = HIR"\n眼见$n迅速变换步法，$N只好招式突换，一棍随手挥出！\n"NOR;
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/attack", -extra/2);
			me->add_temp("apply/damage", -extra/2);
		}

	}
	me->perform_busy(2);
	return ;
}


void get_up(object me,object target)
{
	if(!target || !living(target) || target->is_ghost())
		return ;
	message_vision(YEL "\n\n$N在地上打了几个滚，忍着疼痛狼狈不堪地爬了起来！！\n\n" NOR, target);
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
