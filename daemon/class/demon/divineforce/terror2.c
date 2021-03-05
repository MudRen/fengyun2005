// Modifiction of Terror 1, leave one to kill

#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl,i,j,k=0,l,n;
	object *enemy,*enemy_here;

	if (!me->is_fighting())
		return notify_fail("「妖魔现形」只能对战斗中的对手使用。\n");
	
	enemy = me->query_enemy();
			
	msg = HIG "\n$N容色狰狞，双手结奉邪灵印，口中念念有词，骤然一挥双手，\n"HIM"\n只听一声爆炸声响，数道烟气在$N面前聚集成形，幻化为数丈高下的巨大妖魔！\n\n" NOR;
	message_vision(msg, me);
	
	lvl = me->query_skill("force");

	n = random(sizeof(enemy));
	
	for (i=0; i<sizeof(enemy);i++ )
	{
		if (random(enemy[i]->query("combat_exp")) > me->query("combat_exp") || i == n)
		{
			msg = WHT "$N不为所动，冷笑道：旁门左道，也敢来丢人现眼？\n" NOR;
			message_vision(msg, enemy[i]);
			k++;
		}
		else
		{
			msg = MAG "$N大惊失色，夺路而逃！\n" NOR;
			message_vision(msg, enemy[i]);
			enemy[i]->add_temp("apply/agility",me->query("agi")*2);
			l = enemy[i]->query_busy();
			enemy[i]->stop_busy();
			for (j=0; j<random(3)+3; j++)
			{
				if (environment(enemy[i]) == environment(me))
					GO_CMD->do_flee(enemy[i]);
			}
			enemy[i]->add_temp("apply/agility",-me->query("agi")*2);
			enemy[i]->perform_busy(l);
			if (environment(enemy[i]) != environment(me))
			{
				tell_object(enemy[i],HIY"你逃出生天，不由暗暗抹了一把冷汗，喘息不定。\n"NOR);
				enemy[i]->perform_busy(10);
			}
		}
	}

	return 1;
}


