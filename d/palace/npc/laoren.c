inherit NPC;

void create()
{
        set_name("驼背老者", ({ "laozhe" }) );
        set("gender", "男性" );
        set("age", 68);

        set("long","这是一位久经风霜的驼背老人。\n");
	set("bellicosity",1000000);
        set("combat_exp", 200000);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 100);
        set_skill("zuixian-steps", 100);
	
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object me;
        me = this_player();
        if( interactive(me))
                if (me->query("class") && me->query("class") != "yinshi")
                kill_ob(me);

}

