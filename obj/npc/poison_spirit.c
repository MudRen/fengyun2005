#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
    set_name("毒灵", ({ "poison spirit","spirit" }) );
    set("race", "蛇类");
    set("age", 1);
    set("gender", "雄性");
    set("long", "一团碧绿的浓雾，看不清里面是什么。 \n");
    set("attitude","peaceful");
	set("weight", 300);
	
	set("combat_exp", 10000000);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
    	(: use_poison :),
    }));
    setup();
}


void use_poison()
{
    object *enemy, ob;
    string msg;

    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	message_vision(HIG"$N吐着艳红的舌头，一道细如蚕丝的绿光飞出，冲向$n。\n"NOR, this_object(),ob);
    tell_object(ob,HIC"你只觉得腿上一麻，一阵寒气顺着经脉流走全身。\n"NOR);
    ob->receive_wound("kee",50,this_object());
}

void invocation(object who)
{
	int i, level;
	object *enemy;
	
	level = who->query("combat_exp")*2/3;
	set("combat_exp", level);
	"/feature/nada"->reset_npc(this_object());    
    set("max_kee", 1);
    full_me();
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else {
				enemy[i]->kill_ob(this_object());
				enemy[i]->kill_ob(who);
			}	
		}
	}
	set("leader",who);
	set("possessed",who);
	return;
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
        object owner,snakesword;
		owner = query("possessed");
		if (objectp(owner))	owner->add_temp("max_snake",-1);
		message_vision("$N噗嗤一声消散了。\n",this_object());
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
		destruct(this_object());
		return;
}

void unconcious(){
	die();
}

void die()
{
	object owner;
	owner= query("possessed");
	if (objectp(owner))	owner->add_temp("max_snake",-1);
	message_vision("$N噗嗤一声消散了。\n",this_object());
	destruct(this_object());
	return;
}
