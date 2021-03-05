
inherit SMART_NPC;

void create()
{
	set_name("护寺喇嘛", ({ "lama"}) );
	set("gender", "男性" );
	set("age", 35);
	set("str", 20);
	set("long", @LONG
一个大昭寺的藏僧。
LONG
);
	set("class","lama");
	set("attitude", "heroism");
        set("combat_exp", 26000);
        create_family("大昭寺", 24, "弟子");
        
        set_skill("unarmed", 100);
        set_skill("bloodystrike", random(20)+50);
        set_skill("force", 40);
		set_skill("iron-cloth", 20);
		map_skill("unarmed", "bloodystrike");
	
	
		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
		setup();
		if(random(5)==1)
        	carry_object(BOOKS"magic_41");
        if (random(2)) carry_object(__DIR__"obj/fake-tooth");
        carry_object(__DIR__"obj/redcloth")->wear();
}
