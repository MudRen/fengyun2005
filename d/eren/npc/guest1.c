inherit NPC;

void create()
{
        set_name("满头珠翠的妇人", ({ "guest woman","woman" }) );
        set("gender", "女性" );
        set("age", 33);
        set("long", "一个打扮得珠光宝气的妇人。\n");
        
        set("combat_exp", 800000);
        
		set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        
            	      
        set("chat_chance", 1);
        set("chat_msg", ({
			"妇人嘀咕道：马上就要行礼了，怎么新人还没到。。\n",
		 }) );
        setup();
    	carry_object("/obj/armor/cloth",([	"name": "红底碎花衣",
					"long": "漂亮的衣服。\n",
					 ]))->wear();    
}
