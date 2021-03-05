#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
        set_name("毒蛤蟆", ({ "bad frog","frog" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只剧毒的的癞蛤蟆\n");
		set("attitude", "aggressive");
		set("bellicosity", 300 );
	       
        set_skill("dodge", 200);
        set("combat_exp", 100000+random(999999));
	
	
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if(sizeof(enemy) ) 
        	ob = enemy[random(sizeof(enemy))];

        tell_object(ob,WHT"你觉得身上一麻，身手已经不如刚才灵活了。\n"NOR);
		ob->receive_wound("kee",40,this_object());
        ob->apply_condition("unknown",this_player()->query_condition("unknown") + random(3)+3);
}


