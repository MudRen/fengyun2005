// 特点，持续杀神

#include <ansi.h>
#include <combat.h>
inherit NPC;
int smart_fight();

void create()
{
	object weapon;
        set_name("萧小初", ({ "xiao xiaochu","xiao","xiaochu" }) );
        set("title",WHT"山眉动树影"NOR);
		set("nickname",MAG"一生倥惚一生休"NOR);
        set("gender", "女性" );
		set("class","swordsman");
		set("age",33);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
//		set_temp("apply/haste",200);

        set_skill("zen", 300);
        set_skill("buddhism", 300);
        set_skill("lamaism", 300);
        set_skill("xiaodao", 800);
		
		set_skill("perception",200);
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
        set_skill("shuaijiao",240);
        set_skill("shadowsteps",360);
        set_skill("liuquan-steps",300);

        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "shuaijiao");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("staff", "fumostaff");
        map_skill("force", "snowforce");
        map_skill("sword", "demosword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "liuquan-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(MAG"淡紫旗袍"NOR, ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


}



int smart_fight()
{
	object *inv;
	object target;
	int a;
	
	target = select_opponent();
	
	if (query("av")+ 20 < time())	{		// onece every 10 turns, keep pfm till succeed
		a = target->query("eff_sen");
		ccommand("perform dodge.liushuichanchan");
		if (a > target->query("eff_sen") + 10)
			set("av", time());
	}
	
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


