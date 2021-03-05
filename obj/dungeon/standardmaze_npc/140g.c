// 特点：一个较强杀伤的perform

#include <ansi.h>
inherit NPC;
void smart_fight();
#include <combat.h>

void create()
{
	object weapon;
        set_name("宇文沧", ({ "yuwen can","yuwen","can" }) );
        set("title",WHT"单锋行天下"NOR);
		set("nickname",MAG"来何汹涌须挥剑"NOR);
        set("gender", "男性" );
		set("class","shaolin");

		set("age",33);
//		set("per",37);

		set("no_busy",2);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );
//		set_temp("apply/haste",200);
        set_skill("zen", 300);
        set_skill("buddhism", 300);
        set_skill("lamaism", 300);
        set_skill("xiaodao", 800);

        set_skill("unarmed", 250);
        set_skill("fumostaff", 220);
        set_skill("demosword", 220);
        set_skill("staff", 220);
        set_skill("yizhichan", 220);
        set_skill("dabei-strike", 350);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("force", 220);
        set_skill("snowforce", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);
        set_skill("stormdance", 200);
        set_skill("lingxi-zhi", 200);
        set_skill("calligraphy",360);


        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "yizhichan");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("staff", "fumostaff");
        map_skill("force", "snowforce");
        map_skill("sword", "demosword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "tie-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("护身剑气", ({ "forcefield" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name("单锋剑", ({"sword" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wield();
}




void smart_fight()
{
	object *inv;
	int i;
	ccommand("perform zhutianjianzhen");

	return;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


