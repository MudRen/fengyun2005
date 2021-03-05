// 8个此NPC可以在4分钟内99.9%不受伤害的做掉chi you，chi you死的时候还busy 30+...

#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("虹", ({ "neon","foxgirl" }) );
        set("gender", "女性");
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
		set("no_fly",1);
		set("no_arrest",1);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	auto_npc_setup("neon",300,220,0,"/obj/weapon/","fighter_w","starrain",4);
       setup();    
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade");
	carry_object("/questnpc/obj/leaf")->wield();
	setup();
}

/*
update here;clone /d/bashan/npc/yawnboy;update /adm/daemons/smartd;update /std/char/npc_ann;update /d/bashan/npc/yawngirl3;clone;call justdoit->ccommand(kill sinny)
*/
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
