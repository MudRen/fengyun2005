// ghost.c

inherit NPC;

void create()
{
        set_name("战魂", ({ "ghost", " warrior ghost" }) );
        set("age", 45);
        
        set("str", 24);
        set("cor", 26);

        set("env/wimpy", 70);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set("chat_chance", 1);
	set("combat_exp",random(10000));
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
}

int is_ghost() { return 1; }
