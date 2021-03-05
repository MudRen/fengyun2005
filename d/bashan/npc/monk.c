#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("和尚", ({"shaolin monk","monk"}) );
        set("gender", "男性" );
		set("title","少林高僧");
		set("long","这是个白眉老僧，面目慈祥，看来没一百岁，也有九十\n岁，动作庄重持成，一望而知是个有道高僧。\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
        
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

		set("age",93);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","．．．你在崖上，他在崖底，如何打听得着？\n");
	set("NO_KILL","你在崖上，他在崖底，如何能碰得着？\n");
	set_temp("condition_type",NOR CYN" <山崖下>"NOR);
	
	auto_npc_setup("shaolin monk",300,220,1,"/obj/weapon/","fighter_w","tianlongwhip",1);
	set("perform_busy_u","shaolin/whip/tianlongwhip/sizhuatianlong");
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
