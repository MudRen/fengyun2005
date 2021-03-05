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

	msg = YEL "$N阴笑一声,从怀里掏出个奇形怪状的镜子.\n" NOR;
	msg = msg + HIW "光芒闪烁，刹那间万籁俱寂。\n" NOR;
	
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
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		obj->die();
		return 1;
	}
	return 1;
	
}

