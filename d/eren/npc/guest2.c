inherit NPC;

void create()
{
        set_name("不耐烦的宾客", ({ "guest man","man" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个穿着华丽的宾客。\n");
        
        set("combat_exp", 1000000);
        
		set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
                
        set("chat_chance", 1);
        set("chat_msg", ({
			"宾客叫道：新娘子、新娘子在哪里？\n",
		 }) );
        setup();
    	carry_object("/obj/armor/cloth",([	"name": "上好的长袍",
					"long": "漂亮的衣服。\n",
					 ]))->wear();    
}
