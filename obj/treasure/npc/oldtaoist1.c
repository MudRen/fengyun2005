#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;

        set_name("种桃道人", ({"taoist elder","taoist","elder"}) );
        set("gender", "男性" );
		set("title","武当耄宿");
		set("nickname",HIW"北极"NOR);
		set("age",71);
		set("long","他童颜鹤发，仙风道骨，一副世外高人的模样，\n正是武当派久不涉世的长老人物。\n");
        set("combat_exp", 9000000);
      set("attitude", "peaceful");
			set("spawn_location","/d/wudang/pine3");
			set("group","wudang");
			set("max_kee",100000);
			set("max_sen",100000);
			set("max_gin",100000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "种桃道人皱着眉头，哼道：八弟到哪里去了？解个手用这么久么？\n",
        }) );

		set("no_fly",1);
		set("no_arrest",1);
    		set("real_boss",1);
    set("boss",1);
		set("big_boss",1);
	   
		set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
			(: ccommand("perform dodge.bazhentu") :),
//	       	(: auto_smart_fight(100) :),    
        }) );

		auto_npc_setup("wudang taoist",300,220,0,"/obj/weapon/","fighter_w","taiji-sword",2);
		set("perform_busy_w","wudang/dodge/five-steps/bazhentu");
		set("perform_unarmed_attack","wudang/dodge/five-steps/bazhentu");
		set("perform_unarmed_attack2","wudang/dodge/five-steps/bazhentu");
		setup();

   	weapon=carry_object("/obj/weapon/sword");
    weapon->set_name(HIC"种桃剑"NOR, ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();
		weapon->set("nodrop_weapon");
    weapon=carry_object("/obj/armor/cloth");
    weapon->set_name("纯黑道袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",1);
	set("drop/common_drop",({
		__DIR__"obj/cq2",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );
	
}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
	::die();
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
