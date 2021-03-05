// 天罡伏魔咒对鬼魂有较大的伤害力。

#include <ansi.h>
inherit SSERVER;
int thunderspell(object me, object obj,int flag);

int cast(object me)
{
	string msg;
	object env;
	object *inv, *myteam;
	int i, k, j, cost, lvl;
	int flag;

	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫的弟子才能够使用『天罡伏魔』。\n");
	}
	lvl = me->query_skill("necromancy", 1);
	if( lvl < 100 ) {
		return notify_fail("『天罡伏魔』需要100级三清道术！\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("只有在战斗中才能使用『天罡伏魔』。\n");
	}
	if( ANNIE_D->check_buff(me, "manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	cost = lvl * flag;
	if( me->query("mana") < cost || me->query("sen") <= cost/2 ) {
		return notify_fail("『天罡伏魔』需要"+ cost/2 + "点心神和"+ cost + "点法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -cost);
		me->receive_damage("sen",cost/2);
	}

	msg = BBLU + HIY "\n$N"BBLU + HIY "脚踩天罡步，手握伏魔印，口念咒文，猛地双手一挥，天上打下无数闪电！"NOR+HIC"
			 '$$F                 .$$D
				 $$$                z$$'
				 4$$               d$$b.
				 .$$%            .$$*'*$$e.
			  e$$$*'            z$$'    '*$$e.
			 4$$'              d$D'        '*$$e.
			 $D              .d$$$c           '*$$e..
			d$'             z$$' *$b.            '*$L
		   4$'             e$D'   '*$c            ^$$
		   $'            .d$'       '$$.           ^$r
		  dP            z$$'         ^*$e.          'b
		 4$            e$D             '$$           '
					  J$F               $$
					  $$                 "NOR; 

	message_vision(msg, me);
	inv = me->query_enemy();
	for( i = 0; i < sizeof(inv); i++ ) {
		thunderspell(me, inv[i], flag);
	}
	me->perform_busy(2);
	return 1;
}

int thunderspell(object me, object obj,int flag)
{
	int lvl, spi, kar, kee, damage, spells;
	//	message_vision(YEL "\n一个闪电向$N"NOR+YEL"的头上打来，\n" NOR, obj);
	lvl = me->query_skill("necromancy", 1);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack(me, obj, "spells", "sen", 0) ) {
		message_vision(HIR"\n$N"HIR"惨叫一声，顶门血光崩现，魂飞魄散！\n"NOR, obj);
		// 550+140  = 690. to real ghost *2
		spells = me->query_skill("spells");
		damage = F_LEVEL->get_level(me->query("combat_exp"))+spells;
		if( flag == 3 ) {
			damage*=2;
		}
		if( (obj->is_ghost() || obj->is_zombie()) && !obj->query("ghostcurse") ) {
			damage = COMBAT_D->magic_modifier(me, obj, "sen", damage*2);
		} else {
			damage = COMBAT_D->magic_modifier(me, obj, "sen", damage);
		}
		damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt2_add",3)*2)/100;
		obj->receive_damage("sen", damage, me);
		COMBAT_D->report_status(obj);
		COMBAT_D->win_lose_check(me,obj,damage);
	} else {
		message_vision(RED "\n但被$N"NOR+RED"机灵地躲过了！\n" NOR, obj);
	}
	me->add_temp("apply/spells",-lvl*2);
	return 1;
}