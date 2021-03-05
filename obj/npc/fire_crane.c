
#include <ansi.h>

inherit NPC;
void backattack();
void create()
{	
        set_name( HIR"火鹤"NOR , ({ "fire crane","crane" }) );
        set("race", "飞禽");
        set("age", 1000);
        set("long", "一只浑身羽毛通红的巨鹤。\n");
        set("max_kee", 1000);
		set("max_sen", 1000);
		set("max_gin", 1000);
		set("str",50);
        set("no_arrest",1);
        
		set("combat_exp", 200000);
		set_skill("unarmed", 50);
		set_skill("parry", 50);
		set_skill("dodge", 50);
		set_skill("move", 50);
		set_skill("perception",1);
	
		setup();

}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	if (environment())
	message("vision", "\n"+ name() + HIR"腾空而起，转瞬消失在白云之间。\n"NOR , environment(),
		this_object() );
    
    if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("max_bird",-1);
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
	set_skill("unarmed", 100 + level/2+random(level)/2);
	set_skill("parry", 100 + 3*random(level)/2+3*level/2);
	set_skill("dodge", 100 + 3*random(level)/2+3*level/2);
	set_skill("move", 100 + 3*random(level)/2+3*level/2);
	set("str",30+random(level/5)/2+level/10);
	set("combat_exp", 300000 + level/8*level*level/2+random(level/8*level*level)/2);
	enemy = who->query_enemy();

	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}


void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_bird",-1);
	::die();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	object owner;
	owner = me->query("possessed");
	if (!owner) return;
	dam = owner->query_skill("magic",1);
	message_vision(HIR"\n$N"HIR"双翅扇动，热焰四射，$n被灼烧得焦头烂额。\n"NOR,me,victim);
	victim->receive_wound("kee",dam*2 + random(dam*2), me);
	return;
}

void unconcious() {
	die();
}

void heart_beat()
{
	object leader;
	
	::heart_beat();

	if(!this_object()) 
		return;
			
	if(query_temp("is_unconcious")||is_busy())
		return ;
	if(query("possessed"))
	{
		leader=query("possessed");
		if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N腾空离去。\n",this_object());
			this_object()->move(environment(leader));
			message_vision("$N飞了过来。\n",this_object());
			delete("leave_room");
		}
	}
	
	else
	{
		if(!query("leave_room"))
			set("leave_room",1);
		else
			add("leave_room",1);
		if(query("leave_room")==5)
			leave();
	}
}