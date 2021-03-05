inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();
	
void create()	
{
    	object weapon;

		set_name("古松居士", ({ "boss gusong","boss", "gusong","jushi"}) );
		set("title",HIR"风云第一大乌龟壳"NOR);
		set("gender", "男性" );
		set("class","wudang");
		set("age",41);
		
		set("agi",40);
		
		set("spawn_location","/d/ghost/xting");
    	set("gender", "男性" );
       	
       	set("gold", 2);
		
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );

        set("combat_exp", 1100000);	// L30: Cap @ L30.
    
        set_skill("spells", 200);
        set_skill("qixing",200);	
		
		set_temp("pfm/taiji_siliang",1);

        set_skill("sword", 130);
        set_skill("parry", 130);
        set_skill("taiji-sword",130);	
		set_skill("dodge", 130);
		set_skill("five-steps",110);
		
        set_skill("unarmed", 150);
        set_skill("taiji",120);	
		
        set_skill("force", 200);
        set_skill("taijiforce",50);	
		
        set_skill("incarnation", 250);
        set_skill("iron-cloth", 100);
		
		map_skill("dodge","five-steps");
		map_skill("unarmed", "taiji");
		map_skill("sword", "taiji-sword");
		map_skill("parry", "taiji-sword");
        map_skill("spells", "qixing");
        map_skill("iron-cloth", "incarnation");
        map_skill("force", "taijiforce");
		
		set("max_kee",8000);
		set("max_gin",4000);
		set("max_sen",4000);
		
        add_temp("apply/damage",50);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(YEL"木萧剑"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		
//		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(CYN"仙风道袍"NOR, ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();

		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({
			BOOKS"learn/magic_60",
			BOOKS"learn/spells_100",
			BOOKS"learn/iron-cloth_75.c",
		}));
		set("drop/bg",0);
		set("drop/common",100);
		set("drop/rare",0);	
		set("drop/amount",2);
		set("drop/common_drop",({
"/obj/generate/surcoat_25_14.c",
"/obj/generate/neck_25_2.c",
"/obj/generate/head_25_2.c",
"/obj/generate/cloth3_25_12.c",
"/obj/generate/cloth1_25_2.c",
"/obj/generate/boots_25_3.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

	::die();
	return;
}

int kill_ob(object who)
{
        ::kill_ob(who);
//        smart_fight();
        return 1;
}

void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	int i;
	object me = this_object();

	set("mana",query("max_mana")*2);

	// 守字诀仅对剑法有用，所以这里。。摆个花架子啦。
	if (me->query_temp("timer/shouzijue")+ 40 < time()) {
		msg = HIC "$N使出『守字诀』，凝神专志，拳圈逐渐缩小，将一套太极拳法使得圆转如意，
严密异常的守住门户，竟是无懈可击。\n"NOR;
		message_vision(msg, me);
		me->set_temp("timer/shouzijue",time());
	}
	
	if (!ANNIE_D->check_buff(me,"armorup"))
		ccommand("cast hanxing");
	
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

