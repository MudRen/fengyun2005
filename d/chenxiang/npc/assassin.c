#include <ansi.h>
#include <command.h>

inherit SMART_NPC;


void create()
{

	set_name("无名刺客",({"assassin"}));
    set("long", "一个衣着普通的的中年人，手持一把利剑。\n");
	set("age",37);
	set("combat_exp", 3000000);
        	
	set("nb_chat_chance", 100);
    set("nb_chat_msg_combat", ([
	     	10: 	"\n无名刺客说：拿人钱财，替人消灾！！！\n",
     ]) ); 
        
    set("agi",25);
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),    
    }) );
        
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	setup();
	set_skill("perception",200);		// NO shooting !
	carry_object("/obj/armor/cloth")->wear();
	carry_object(AREA_FY"npc/obj/killersword")->wield();
}



int heal_up()
{
	if(!is_fighting()) {
//		command("say ok");
		message_vision(CYN"无名刺客唿哨一声，跳进小西湖里消失了。\n"NOR, this_object());
		destruct(this_object());
		return 1;
	}
	return ::heal_up() + 1;
}


void init(){
	
	object *inv;
	int i;
	
	::init();
	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("qingbo"))
			kill_ob(inv[i]);
	}
}
	
	
void die(){
	
	object qb, prot;
	object qingbo;
	
	qb = present ("prince qingbo");
	if (objectp(qb)) {
		prot = qb->query_temp("marks/protector");
		if (objectp(prot) && prot->is_fighting(this_object()))
		{
			if (REWARD_D->riddle_check(prot,"魂断鹊桥")==2)
				REWARD_D->riddle_set(prot,"魂断鹊桥",3);
		}
	}
	if (qingbo=present("prince qingbo"))
		qingbo->command("touch");
	
	message_vision(BLU"\n\n$N叫道：点子扎手，扯呼！一头又扎进了小西湖里。\n\n"NOR, this_object());
	
	destruct(this_object());
	
}
			
		
void unconcious(){
	die();
}
