#include <ansi.h>
#include <command.h>

inherit SMART_NPC;


void create()
{

	set_name("衣衫惨绿的中年人",({"middle age man","man"}));
    set("long", "衣衫惨绿的中年人，手持一把短剑。\n");
	set("age",37);
	set("combat_exp", 5000000);
        	
	set("pursuer", 1);
	set("marks/parrot_killer",1);
	
    set("death_msg",CYN"\n$N说：完了，攒的银子再多有什么用。。 \n"NOR);

        set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n中年人说：我们什么事都不管，只管杀人！！！\n",
        ]) ); 
    
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(50) :),    
        }) );
        
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	set_skill("move",800);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(AREA_FY"npc/obj/killersword")->wield();
}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}