#include <ansi.h>
inherit SSERVER;
int thunderspell(object me, object obj);

int perform(object me, object target)
{
	string 	msg;
	object	env,weapon;
	object	*inv;
	
	int	i;
	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");

	msg = HIR "$N喝道：接招！！\n" NOR;
	if (weapon = me->query_temp("weapon"))
		msg = msg + HIW "$N一抖手中的"NOR+weapon->name()+"，"+weapon->name()+HIW"散作点点星光溅射而出！\n\n" NOR;
	else msg = msg + HIW "$N左手一挥，内家罡气散作点点星光溅射而出！\n\n" NOR;
	
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(1);
	return 1;
}


int thunderspell(object me, object obj)
{
	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
		
	obj->receive_damage("sen", 0, me);
	
	if(obj->is_ghost()==1) {
		message_vision(HIW "一点寒星正击在$N额头之上！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(HIW "一点寒星正击在$N额头之上！\n" NOR, obj);
		obj->die();
		return 1;
	}

	return 1;
	
}

