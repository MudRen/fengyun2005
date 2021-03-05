inherit SMART_NPC;
int give_qin();

void create()
{
        set_name("云明", ({ "yunming" }) );
        set("gender", "男性" );
        set("class", "bonze");
	set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);
        
        set("long", "他是兴国禅寺中颇有威望的云字辈大师。\n");
        set("combat_exp", 3500000);
        set("attitude", "friendly");
        
		set("no_busy",5);
	              
        set_skill("dabei-strike",150);
        set_skill("notracesnow",150);
        set_skill("unarmed", 200);
    	set_skill("force", 200);
    	set_skill("dodge", 200);
    	set_skill("parry", 120);
	    set_skill("cloudstaff", 170);
	    set_skill("lotusforce", 150);
	    set_skill("notracesnow",150);
	    set_skill("dabei-strike",150);
	    set_skill("move",120);
		set_skill("essencemagic",150);
		set_skill("magic",150);
        set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);
    
        map_skill("spells","kwan-yin-spells");  
		map_skill("magic","essencemagic");
	    map_skill("move","notracesnow");
	    map_skill("force", "lotusforce");
	    map_skill("dodge","notracesnow");
	    map_skill("unarmed","dabei-strike");
		
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
       
        set("chat_chance", 1);
        set("chat_msg", ({
                "云明说道：你想学敲钟吗？\n",
        }) );
        set("inquiry", ([
		"敲钟" : (: give_qin :),
		"qiaozhong" : (: give_qin :),
	]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
        carry_object(__DIR__"obj/zhongbook");
}



int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}

int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say 这把佛钟你拿去练吧！！\n");
obj = new(__DIR__"obj/fezhong");
obj->move(this_player());
set("given",1);
        }
else
command("say 我的佛钟已送人了！\n");
        return 1;
}

void reset()
{
delete("given");
}

