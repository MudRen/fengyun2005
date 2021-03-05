#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("阿水", ({ "sinny"}) );
        set("gender", "男性" );
        set("title","快活林色使传人");
        set("age", 32);
        set("long", "\n");
        set("combat_exp", 8000000);
        set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","．．．你在崖上，他在崖底，如何打听得着？\n");
	set("NO_KILL","你在崖上，他在崖底，如何能碰得着？\n");
	set_temp("condition_type",NOR CYN" <山崖下>"NOR);


	auto_npc_setup("sinny",300,220,1,"/obj/weapon/","fighter_w","xuanyuan-axe",2);
	
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
