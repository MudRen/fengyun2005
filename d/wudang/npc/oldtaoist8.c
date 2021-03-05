#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;

	string tt;
	tt = "听风";

        set_name(tt+"道人", ({"taoist elder","taoist","elder"}) );
        set("gender", "男性" );
		set("title","武当耄宿");
		set("nickname",HIY"摇光"NOR);
		set("age",71);
		set("long","他童颜鹤发，仙风道骨，一副世外高人的模样，\n正是武当派久不涉世的长老人物。\n");
        set("combat_exp", 7000000);
        set("attitude", "peaceful");

		set("group","wudang");

        set("chat_chance", 1);
        set("chat_msg", ({
                "听风道人好奇地绕着松树转来转去，嘴里不知道在嘀咕着什么。\n",
                "听风道人喃喃道：这到底是什么含义？\n",
        }) );


	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

		set("no_fly",1);
		set("no_arrest",1);
       
	auto_npc_setup("wudang taoist",300,220,0,"/obj/weapon/","fighter_w","taiji-sword",2);

	setup();

     	tt=HIC+tt+"剑"+NOR;
	   weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(tt, ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("纯紫道袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();


}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
