inherit SMART_NPC;

void create()
{
        set_name("关东豪客", ({ "guandong haoke", "haoke" }) );
        set("gender", "男性" );
        set("age", 32+ random(10));
        set("long", "这是一位从白山黑水来的大汉，手下带着一群行旅商人。\n");
        set("combat_exp", 3200000);
        set("class","knight");
        set("chat_chance", 1);
        set("chat_msg", ({
                "关东豪客豪爽得向你大笑！\n",
        }) );
        	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","zhangjian",1);
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/xuechang");
}