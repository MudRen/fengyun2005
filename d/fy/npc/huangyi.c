
inherit NPC;

void create()
{
        set_name("黄衣卫", ({ "yellow guard", "guard"}) );
        set("gender", "男性" );
        set("age", 32);
	set("cor",15);
        set("long", "这是一位金钱帮总舵的黄衣卫。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        
        set_skill("sword", 30);
	set_skill("dodge", 50);
	set_skill("lefthand-sword", 30);
        map_skill("sword","lefthand-sword");
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
        }) );
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "黄衣卫向你喝道：口令？？\n",
                "黄衣卫向你喝道：站住．亮你的腰牌？\n",
        }) );
	
	setup();
	
        carry_object(__DIR__"obj/tangfu")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

