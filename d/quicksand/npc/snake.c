inherit NPC;
void use_poison();

void create()
{
        set_name("响尾蛇", ({ "snake" }) );
        set("race", "蛇类");
        set("age", 4);
		set("long", "一条剧毒的响尾蛇。\n");

        set_skill("dodge", 50);
        set("bellicosity", 300 );
        
        set("combat_exp", 5000 + random(50000));      
        
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
    	if (!random(2)) carry_object("/d/shanliu/npc/obj/xiangweishedan");
}

void use_poison()
{
        object *enemy, ob;
//      string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,"你觉得脸上剧痛，伸手一摸发现两个毒牙印痕。\n");
        ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}
