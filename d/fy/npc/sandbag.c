inherit NPC;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("多嘴的大沙包", ({ "big sandbag","sandbag" }) );
        set("gender", "男性" );
        set("long", "一个看上去怎么也打不死的大沙包（max_kee 25000），似乎专为人训练打斗而设。\n");
 //       set("long", "（max_kee 25000\max_gin 20000\max_sen 20000）\n");
        set("class", "legend" );
        set("age", 21);
        set("per", 40);
        
        set("max_kee", 25000);
        set("max_gin", 20000);
        set("max_sen", 20000);

        set("force_factor", 50);
        set("no_arrest", 1);
        set("attitude", "friendly");
		set("combat_exp", 300000);        

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 120);
        
        set("chat_chance", 1);
        set("chat_msg", ({
    		"多嘴的大沙包朗声道：在下不会说话。但你不服可以来打我啊，打我啊。。。\n",
        }) );
        
        set_skill("spring-water", 1);
        set_skill("fall-steps", 120);
        set_skill("diesword", 70);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("iron-cloth", 10);
        set_skill("parry",120);
        
        map_skill("parry","diesword");
        map_skill("sword","diesword");
		map_skill("iron-cloth","spring-water");
      	map_skill("dodge","fall-steps");
                
        setup();
//        carry_object("/d/fugui/npc/obj/redcloth")->wear();
        carry_object("/obj/weapon/sword_l")->wield();
}

void die()
{
    	object me;
    
    	if(objectp(me = query_temp("last_damage_from")) && !query("leaving")){
	    	message_vision(HIG"$N纵身向后跃去，微一凝气，脸色又恢复了红润。\n"NOR,this_object(),me);
    	} 
    	full_me();
}


void unconcious()
{
        die();
}
