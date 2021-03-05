#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
    set_name(HIY"王蛇"NOR, ({ "wang snake", "snake" }) );
    set("race", "蛇类");
    set("age", 1);
    set("gender", "雄性");
    set("long", "一条全身金色的小蛇，你可以把它杀了取胆，其蛇胆据说可以医治许多疑难 
杂症。 \n");
    set("attitude","peaceful");
    set("weight", 300);
    set("combat_exp", random(100000));
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
	message_vision(HIY"只见一道金光飞起，冲向$N。\n"NOR, ob);
    tell_object(ob,HIC"你只觉得腿上一麻，一阵寒气顺着经脉流走全身。\n"NOR);
    ob->receive_wound("kee",50, this_object());
    ob->apply_condition("canxia", 
    	(int)this_player()->query_condition("canxia")
    	+ random(2)+1);
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
        object playsnakebeggar;
		if (playsnakebeggar = present("playsnake beggar",environment(this_object())))
        {
			message_vision("$N刺溜一声，钻进的$n布袋中不见了\n",this_object(),playsnakebeggar);
        }else
		{
			message_vision("$N刺溜一声,迅速的游走了\n",this_object());
		}
        destruct(this_object());
}


void die()
{
	object sedan;
	sedan = new(__DIR__"obj/wangshedan");
	sedan->move(this_object());
	::die();
}