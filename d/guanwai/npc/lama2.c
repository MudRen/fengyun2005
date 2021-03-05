
inherit SMART_NPC;

void create()
{
	set_name("护寺藏尼", ({ "zang ni", "ni"}) );
	set("gender", "女性" );
	set("age", 25);
	set("str", 20);
	set("long", @LONG
一个大昭寺的藏尼。
LONG
);
	set("class","lama");
	set("attitude", "peaceful");

        set("combat_exp", 16000);
        create_family("大昭寺", random(4)+24, "弟子");
        
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	set_skill("iron-cloth", 10);
	map_skill("unarmed", "bloodystrike");

		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();
        if(random(5)==1)
        	carry_object(BOOKS"spells_41");
        if (random(2)) 
        	carry_object(__DIR__"obj/fake-tooth");
        carry_object(__DIR__"obj/redcloth2")->wear();
	carry_object(__DIR__"obj/1staff")->wield();
}
