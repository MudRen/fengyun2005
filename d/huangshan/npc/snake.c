inherit NPC;
void use_poison();

void create()
{
        set_name("竹叶蛇", ({ "big snake" }) );
        set("race", "蛇类");
        set("age", 4);
        set("long", "一条剧毒的全身象竹子的蛇\n");
        
        set("attitude", "aggressive");
        
        set("max_kee",2400);
        set("max_gin",1800);
        set("max_sen",1800);
        
        set("combat_exp", 1200000);
		set_skill("dodge", 200);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
    	if (!random(2)) carry_object("/d/shanliu/npc/obj/zhuyeshedan");
}


void use_poison()
{
        object *enemy, ob;
//      string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,"你觉得腿上剧痛，伸手一摸发现两个毒牙印痕。\n");
		ob->receive_wound("kee",40,this_object());
        ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(10)+10);
}