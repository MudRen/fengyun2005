// sserver.c
// Copyright (C) 1995 - 2005, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

/* Last Modifications

		--- 02/06/2004 By Silencer
			* put in player-selection so NPC will always try to perform on players first.
			  There is also changes in /feature/attack.c to improve opponent selection.
		--- Outdated with HATE-list implementation.
*/


inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
/*	int sz;
	object *enemy, *pc_enemy;
	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	if (!userp(me)) {
		pc_enemy = filter_array(enemy, (: userp($1) :));
		if (sizeof(pc_enemy) >= 1)
			enemy = pc_enemy;
	}		

	sz = sizeof(enemy);
	
	if( sz > 0 ) return enemy[random(sz)];	
	else return 0;	*/
	
	return me->select_opponent();
}
