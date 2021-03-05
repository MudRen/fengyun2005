// TIE@FY3

inherit SMART_NPC;
void create()
{
        //string *name = ({"山烟寺","兴国禅寺","塞外","印度","南山寺","无名寺","黄山","泰庙"});
        set_name("无名寺的和尚", ({ "wild monk", "monk"}) );
        set("gender", "男性");
        set("age", random(90)+10);
        set("long",
                "一个到少林的外寺和尚。\n");
		set("combat_exp", 3000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        		name()+"叹道：少林不愧为禅宗祖庭呀．．\n",
				name()+"道：我看少林也不乏空有虚名者！\n",
                name()+"对你说道：这位小弟，你意下如何？\n",
        }) );

        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		    (: auto_smart_fight(50) :),
     	}) ); 		

		auto_npc_setup("wang",180,180,0,"/obj/weapon/","fighter_w","dabei-strike",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();

}