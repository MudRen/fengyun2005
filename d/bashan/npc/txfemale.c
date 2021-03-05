#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("奇侠", ({"tiexue apprentice","apprentice"}) );
        set("gender", "女性" );
		set("title","铁雪奇侠");
		set("long","这．．．你简直以为自己看见了铁少与雪蕊儿的翻版！！\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
        
	set("no_fly",1);
	set("no_arrest",1);
		set("age",23);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","．．．你在崖上，她在崖底，如何打听得着？\n");
	set("NO_KILL","你在崖上，她在崖底，如何能碰得着？\n");
	set_temp("condition_type",NOR CYN" <山崖下>"NOR);
	
	auto_npc_setup("tiexue apprentice",300,220,1,"/obj/weapon/","fighter_w","diesword",1);
//	set("perform_busy_u","legend/blade/shortsong-blade/daojianruomeng");
	set("perform_busy_d","legend/blade/shortsong-blade/daojianruomeng");
	set("perform_weapon_attack","legend/blade/shortsong-blade/daojianruomeng");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void unconcious()
{
	die();
}

void die()
{
	object *sy_inv,obj;
	int j;
	sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			obj = sy_inv[j];
			destruct(obj);
		}
		set("NO_CORPSE",CYN"\n水如昔身影旋动，将"+name()+"的尸体踢得踪影不见。\n"NOR);
	::die();
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
