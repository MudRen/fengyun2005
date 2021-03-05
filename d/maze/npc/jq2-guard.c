#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("地牢守卫", ({ "guard"}) );
        set("gender", "男性" );
        set("title",YEL"金钱帮  "NOR);
        set("age", 32);
        set("long", "看守金钱地牢的守卫，个个是穷凶极恶之徒。\n");
        set("maze","jq2");
        set("combat_exp", 2500000);
        set("attitude", "aggressive");
        set("pursuer",1);
              
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"喝道：什么人敢私闯地牢！\n",
        }) );
		
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(15) :),    
        }) );
	
		auto_npc_setup("liaoyin",180,170,1,"/obj/weapon/","fighter_w","smallguy",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}