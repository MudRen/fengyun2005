#include <ansi.h>
inherit SMART_NPC;

void questcheck()
{
	object enemy,owner,me, *mem;
	string a,b;
    int i, num;
    
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	
	if (!enemy || !objectp(enemy))
	{
		return;
	}
	else
		me=enemy;	 
		
	// Check self first, we reward ppl who does the killing first.
	
	if (!query("target_name") || query("target_name")=="")	return;
			
	if (query("target_name") == me->query("annie_quest/target")) 			
	{	
		// All annie_quest should be deleted/reset when getting new quests
		// Here we only need to check time.
		if (time()-me->query("quest_time") < me->query("quest/duration"))
		{
			me->add("annie_quest/number",-1);
			if (me->query("annie_quest/number")>0)
			{
				tell_team(me,WHT+me->name()+"杀死了一个"+query("name")+"，离"+me->name()+"的任务完成又近了一步。\n"NOR);
				a= me->query("annie_quest/short");
				b = replace_string(a,"XXX",""+ me->query("annie_quest/number"));
				me->set("quest/short", b);
			} else
			{
				tell_team(me,WHT+me->name()+"杀死了一个"+query("name")+"，完成了"+me->name()+"的任务！\n"NOR);
				me ->delete("annie_quest");	// the next step should delete the quest. 
				QUESTS_D->give_reward(me,me, me->query("quest"));				
			}
			return;
		}
	}
	
	// Team time;
		
	mem = me->query_team();
	num = sizeof(mem);
	
	if (!mem || num <2)	return;
		
	for (i = 0; i< num;i++)	{
		if ( mem[i] == me)	continue;
		if (query("target_name"))
		if (query("target_name")!= mem[i]->query("annie_quest/target"))	continue;
		if (time()- mem[i]->query("quest_time") > mem[i]->query("quest/duration")) continue;
		
		mem[i]->add("annie_quest/number",-1);
		if (mem[i]->query("annie_quest/number")>0)
		{
			tell_team(me,WHT+me->name()+"杀死了一个"+query("name")+"，离"+mem[i]->name()+"的任务完成又近了一步。\n"NOR);
			a= mem[i]->query("annie_quest/short");
			b = replace_string(a,"XXX",""+ mem[i]->query("annie_quest/number"));
			mem[i]->set("quest/short", b);
		} else
		{
			tell_team(me,WHT+me->name()+"杀死了一个"+query("name")+"，完成了"+mem[i]->name()+"的任务！\n"NOR);
			mem[i] ->delete("annie_quest");	// the next step should delete the quest. 
			QUESTS_D->give_reward(mem[i],me, mem[i]->query("quest"));				
		}
		return;	
	}
	
	return;
}




void die()
{
	questcheck();
	::die();
	return;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

