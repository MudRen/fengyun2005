inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
	object weapon;
    	set_name("兰", ({ "lan"}) );
    	set("nickname", BLU"寅"NOR);
    	set("gender", "女性" );
    	set("class","lama");

		set("title",YEL"大光明教"NOR);
    
    	set("reward_npc", 1);
    	set("difficulty", 6);
    
    	set("age", 34);
    	set("per", 35);
    	set("attitude","friendly");
		set("chat_chance_combat", 35);
    	set("chat_msg_combat", ({
        	(: smart_fight() :),
             }) );

    	set("combat_exp", 5100000);
       
        set_skill("unarmed", 180);
        set_skill("staff", 300);
        set_skill("force", 180);
        set_skill("chanting", 190);
        set_skill("parry", 170);
        set_skill("spells",200);
        set_skill("iron-cloth", 200);
        set_skill("fanwen",100);
	
		set_skill("literate", 100);	
		set_skill("perception", 100);
		set_skill("bloodystrike", 200);
		set_skill("fengmo-staff", 180);
		set_skill("bolomiduo", 160);
		set_skill("lamaism", 300);
        set_skill("jin-gang", 200);
        set_skill("kwan-yin-spells",200);
        set_skill("foreknowledge", 100);
    		
		map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "fanwen");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "fengmo-staff");
        map_skill("parry", "fengmo-staff");
        map_skill("spells","kwan-yin-spells");
        
		set_temp("apply/iron-cloth",200);
    	
	   	 setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("春水罗衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

int kill_ob(object who)
{
	::kill_ob(who);

	if (is_busy())
		return 1;
	smart_fight();
	return 1;
}

void smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2) {
		who->cast_spell("ni");
		return;
	}
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_skill("iron-cloth")>300 
				|| enemy[i]->query("combat_exp")> who->query("combat_exp")) {
				ccommand("emote 微微一笑：好厉害的硬功，不过，近日小婢游历关外之时，向葛伦住持学到新本事了呢。");
				ccommand("emote 拈起一张素色的信笺，卷成圆筒凑近嘴边。");
				who->cast_spell("an");
				who->stop_busy();
				who->cast_spell("an");
				who->start_busy(4);
				ccommand("fox");
				return;
			}		
			who->cast_spell("an");
			}
	}
	return;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
