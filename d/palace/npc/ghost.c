// ghost.c

inherit NPC;

void create()
{
        set_name("恶魔亡魂", ({ "ghost", " bad ghost" }) );
        set("age", 45);
        
        set("str", 24);
        set("cor", 26);
	set("combat_exp",2000);
        set("env/wimpy", 70);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
         setup();
}

int is_ghost() { return 1; }
