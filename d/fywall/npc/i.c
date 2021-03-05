// 特点：连击

#include <ansi.h>
inherit NPC;
int smart_fight();
#include <combat.h>

void create()
{
	object weapon;
        set_name("初行雁", ({ "chu xingyan","chu","xingyan" }) );
        set("title",WHT"霜冷秋无影"NOR);
		set("nickname",MAG"花开花落两由之"NOR);
        set("gender", "女性" );
		set("class","demon");

		set("age",33);
		set("per",37);

		set("no_busy",4);

        set("combat_exp", 10000000);

/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );*/
             
		set_temp("apply/haste",200);
        set_skill("zen", 300);
        set_skill("buddhism", 300);
        set_skill("lamaism", 300);
        set_skill("xiaodao", 800);
        set_skill("spells", 200);
        set_skill("qixing",200);	

        set_skill("taiji-sword",200);	
        set_skill("taiji",240);	
        set_skill("dual-attack",240);	

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
        set_skill("taijiforce",200);
        set_skill("kaleidostrike",440);


        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "kaleidostrike");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("staff", "fumostaff");
        map_skill("force", "snowforce");
        map_skill("sword", "demosword");
        map_skill("parry", "qiuzhi-sword");
//        map_skill("dodge", "tie-steps");
        map_skill("dodge", "stormdance");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("丝缕衣", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/d/bashan/mazenpc/obj/wolfclaw");
		weapon->set_name("银狼牙爪", ({"wolf claw","claw" }) );
		weapon->set("long","");
		weapon->set("weapon_prop/damage",15);
		weapon->set("value",0);
		weapon->wield();
}





/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


