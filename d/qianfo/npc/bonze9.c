
inherit SMART_NPC;

void create()
{
        set_name("云林", ({ "yunlin" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);

        set("long", "他是兴国禅寺中颇有威望的云字辈大师。\n");
        set("combat_exp", 7000000);
        set("attitude", "friendly");
               
        set("chat_chance", 1);
        set("chat_msg", ({
                "云林说道：你见主持吗？\n",
        }) );
        set("inquiry", ([
		"主持" : "主持在后园。\n",
		"master" : "主持在后园。\n",
	]));
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","healer",1);
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
        carry_object("/obj/weapon/staff",([	"name": "达摩杵",
    						"long": "一根佛家的禅杖。\n",
    						 ]))->wield();    
}

int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
