#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("周子墨", ({"zhou zimo","zhou"}) );
	set("gender", "男性" );
	set("combat_exp", 11000000);
	set("group","berserker");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set_temp("no_busy",random(3));	// 33% chance no_busy = 2.

	set("age",27);
	set("per",40);

	set("difficulty",32);
	set("reward_npc",1);

   	create_family("明霞山星月斋", 1, "");

	set("nickname",CYN"快雨无行"NOR);

	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("zhou",300,220,0,"/obj/weapon/","fighter_w","tempestsword",4);
	setup();
	carry_object("/d/jinan/npc/obj/dagger2");
	carry_object("/d/jinan/npc/obj/tempestsword")->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"天蓝长衫"NOR, ({ "cloth" }) );
	weapon->set("long","天蓝长衫(Cloth)。");
	weapon->set("value",0);
	weapon->wear();
}

void attempt_apprentice(object ob)
{
	command("shake");
	command("say 你的资质太差了。");
}

int kill_ob(object who)
{
	if (who->is_zombie() == 1 || base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N扬了扬手，空气中点点星光闪烁，刹那间四周万籁俱寂．．．\n" NOR,this_object());
		who->die();
		return 1;
	}
	::kill_ob(who);
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
