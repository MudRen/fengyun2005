#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("李大娘",({"li daniang","daniang","li"}));
//    	set("title",WHT"四大名捕"NOR);
    	set("long", "她的笑容如春花开放，语声如春莺婉转。身材比左右的女人更丰满，相貌也更美。
血奴已是罕见的美人，仍未能与她相比。她就随随便便地坐在那里，已风情万种。\n");
		set("age",47);
		set("combat_exp", 8000000);
        set("attitude", "friendly");	
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
	

	
		auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","sharen-sword",2);
		setup();
		carry_object("/obj/armor/cloth")->wear();
}
