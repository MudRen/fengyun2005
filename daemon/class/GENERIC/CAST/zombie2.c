// zombiebolt.c

#include <ansi.h>
inherit SSERVER;
int thunderspell(object me, object obj);

int cast(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	
	int	i;
	if(userp(me))
		return notify_fail("你所选用的咒文系中没有这种咒文。\n");

	msg = YEL "$N笑道：米粒之珠,也放光华！\n" NOR;
	msg = msg + HIW "$N左手一摆,竟将真力凝成点点寒星激射而出！\n\n" NOR;
	
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
		return notify_fail("你所选用的咒文系中没有这种咒文。\n");
		
	obj->receive_damage("sen", 0, me);
	
	if(obj->is_ghost()==1) {
		message_vision(HIW"寒星正打在$N的额头,$N惨叫了一声，化为灰烬！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(HIW"寒星正打在$N的额头,$N惨叫一声，化为血水！\n" NOR, obj);
		obj->die();
		return 1;
	}

	return 1;
	
}

