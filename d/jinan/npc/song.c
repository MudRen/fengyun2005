#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("宋秋晨", ({"song qiuchen","song"}) );
	set("gender", "女性" );
	set("group","berserker");
	set("combat_exp", 11000000);
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set_temp("no_busy",random(3));	// 33% chance no_busy = 2.

	set("age",24);
	set("per",40);

   	create_family("明霞山星月斋", 1, "");

	set("nickname",WHT"春风融雪"NOR);

	set("difficulty",32);
	set("reward_npc",1);
   
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("song",300,220,0,"/obj/weapon/","fighter_w","spring-blade",4);
	setup();
	carry_object(__DIR__"obj/dagger1");
	carry_object(__DIR__"obj/spring-blade")->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(YEL"淡黄绸裙"NOR, ({ "longskirt" }) );
	weapon->set("long","淡黄绸裙(Longskirt)。");
	weapon->set("value",0);
	weapon->wear();

}

void attempt_apprentice(object ob)
{
	command("shake");
	command("say 我夫妇此次下山游玩，并不曾存有收徒之捻。");
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
