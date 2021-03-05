inherit NPC;
void use_poison();

void create()
{
        set_name("水蛇", ({ "snake" }) );
        set("race", "蛇类");
        set("age", 4);
	set("yes_carry", 1);
        set("long", "一条水桶般粗的水蛇。\n");
        set("attitude", "aggressive");
        set_skill("dodge", 50);
	set_skill("move",300);
        set("combat_exp",10000);
	set("bellicosity", 300 );
        set("chat_chance", 20);

        setup();
}
void use_poison()
{
        object *enemy, ob;
//      string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,
"你觉得脸上剧痛，伸手一摸发现两个毒牙印痕。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
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
