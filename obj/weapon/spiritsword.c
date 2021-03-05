#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
    	set_name("剑芒", ({ "sword spirit"}) );
    	set("age", 1);
    	set("gender", "雄性");
    	set("long", "一条全身莹碧的小蛇。 \n");
    	set("attitude","peaceful");
    	set("limbs", ({ "头部", "身体","尾巴", "七寸" }) );
    	set("verbs", ({ "bite"}) );
	set("no_see",1);
	set("weight", 300);
	set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 9999);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 9999);
        set("sen", 3000); 

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
    ob->receive_wound("kee",50);
    ob->apply_condition("canxia", 
    	(int)this_player()->query_condition("canxia")
    	+ random(2)+1);
}

void invocation(object who)
{
	int level;
	level = who->query("combat_exp")/3000;
	set("str",10+level/20+random(level/20));
    set("combat_exp", 100000 + level/8*level*level/4+random(level/8*level*level)*3/4);
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
		if (objectp(owner) && present(owner,environment(this_object())) && 	(snakesword = present("snake sword",owner)))
        {
			if (snakesword->query("equipped"))
				message_vision("$N刺溜一声，盘进的$n手中的"+snakesword->query("name")+"上不见了。\n",this_object(),owner);
			else
				message_vision("$N刺溜一声，钻进的$n怀中的"+snakesword->query("name")+"上不见了。\n",this_object(),owner);
        }else
		{
			message_vision("$N刺溜一声,迅速的游走了。\n",this_object());
		}
        destruct(this_object());
		return;
}
void die()
{
	object owner;
	owner= query("possessed");
	if (objectp(owner))	owner->add_temp("max_snake",-1);
	message_vision("$N瘫软下来，化为一摊碧血，渐终消失不见。\n",this_object());
	destruct(this_object());
	return;
}