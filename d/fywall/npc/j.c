// random damage from birdiestrike

#include <ansi.h>
inherit NPC;
void smart_fight();
#include <combat.h>

void create()
{
	object weapon;
        set_name("舒石公", ({ "shu shigong","shu","shigong" }) );
        set("title",WHT"抱石枕孤松"NOR);
		set("nickname",MAG"风节自古如残梦"NOR);
        set("gender", "男性" );
		set("class","swordsman");

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
        set_skill("shuaijiao",360);
        set_skill("shadowsteps",300);
		set_skill("birdiestrike", 280);
		set_skill("perception",250);
		
        map_skill("unarmed", "birdiestrike");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("staff", "fumostaff");
        map_skill("force", "snowforce");
        map_skill("sword", "demosword");
        map_skill("dodge", "shadowsteps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("花农装", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();
		
		weapon=carry_object("/obj/weapon/fist");
        weapon->set_name("松枝丫", ({ "ironfist" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->set("weapon_prop/damage",25);
		weapon->wield();

}




void smart_fight()
{
//	object *inv;
//	int i;
	ccommand("perform dodge.lianhuanjiao");
	return;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

