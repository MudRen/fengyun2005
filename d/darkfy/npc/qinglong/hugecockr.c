inherit NPC;
void create()
{
        set_name("巨型蟑螂", ({ "huge cockroach" }) );
        set("race", "野兽");
        set("age", 999);
        set("long", "一只非常巨大的蟑螂。似乎是无言的宠物。 \n");

        set("combat_exp",18000000);
        set("score", 2000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 150);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set("arrive_msg", "飞快地爬了过来");
        set("leave_msg", "飞快地爬开了");
        set("limbs", ({ "头部", "身体"}) );
         set("verbs", ({ "bite" }) );
        set_temp("armor", 300);

    set("chat_chance", 25);
    set("chat_msg", ({
            (: random_move :),
    }) );

        setup();
}


