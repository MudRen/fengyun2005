inherit NPC;
void create()
{
        set_name("孤魂", ({ "ghost", " wandering ghost" }) );
        set("age", 45);
        set("env/wimpy", 70);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set("combat_exp",2000);
        set("chat_chance", 1);
        
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
}

int is_ghost() { return 1; }
