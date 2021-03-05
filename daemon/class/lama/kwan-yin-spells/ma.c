//mimicat@fy4

#include <ansi.h>

int cast(object me, object target)
{
	int i, rate, amount, stage;
	object *enemy, *mem;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用观音六字明咒。\n");
	}
	if( me->query_skill("kwan-yin-spells",1) < 90 ) {
		return notify_fail("此法术至少需要90级观音六字明咒。\n");
	}
	if( !target ) {
		target=me;		
	}
	if( !living(target) ) {
		return notify_fail(target->name() + "已经无法接受你的好意了。\n");
	}
	if( !COMBAT_D->legitimate_heal(me,target) ) {
		return notify_fail("你不能治疗此人（江湖仇杀限制）\n");
	}
	if( target != me ) {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
		}
	}

	stage = me->query("scroll/kwan-yin-spells_ma");
	switch( stage ) {
		// This cast is actully an instant Hate generator, with gin/sen x2 amount hate generated, against all .
		case 0:
		case 1:
			{
				rate = 200;
				amount = 800;
			}
			break;	
		case 2:
			{
				rate = 300;
				amount = 1200;
			}
			break;	// 1.6M		2x = 400->2400 (4SB), 3x=500->3600 (6SB)
	}
	if( (int)me->query("mana") < rate ) {
		return notify_fail("至少需要"+ rate +"点的法力。\n");
	}
	if( !me->query("possessed") ) {
		if( random(100) < F_ABILITY->check_ability(me, "3_ma_add", 3)*2 ) {
			amount = amount*2;
		}
	}
	amount = COMBAT_D->magic_modifier(me, target, "gin", amount);
	if( userp(me) ) {
		me->add("mana", -rate);
	}
	if( target == me ) {
		message_vision(
		YEL "\n$N"NOR+YEL"双手如捧宝盆，拢于身前．聚气凝神喝道『嘛』！\n"
		MAG "如云的紫气从$N"NOR+MAG"双掌间涌出，笼罩在$N"NOR+MAG"头顶，然后慢慢消失。 \n\n" 
		WHT "紫气散去，$N"NOR+WHT"满头是汗水，伤势渐渐愈合。 \n"NOR, me); 
	} else {
		message_vision(
		YEL "\n$N"NOR+YEL"双手如捧宝盆，拢于身前．聚气凝神喝道『嘛』！\n"
		MAG "如云的紫气从$N"NOR+MAG"双掌间涌出，笼罩在$n"NOR+MAG"头顶，然后慢慢消失。 \n\n" 
		WHT "紫气散去，$N"NOR+WHT"满头是汗水，$n"NOR+WHT"的伤势渐渐愈合。 \n"NOR, me, target ); 
	}
	target->receive_fulling("sen", amount,me);
	target->receive_fulling("gin", amount,me);
	if( target->is_fighting() ) {
		enemy = target->query_enemy();
		for( i = 0; i < sizeof(enemy); i++) {
			if( !enemy[i]->is_fighting(me) ) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}	
	}
	me->perform_busy(2);
	return 1;
}
