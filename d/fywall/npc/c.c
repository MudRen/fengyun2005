// 特点：30秒叫一个鹤，10秒伤1000神

#include <ansi.h>
inherit NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("水临烟", ({ "shui linyan","shui","linyan" }) );
        set("title",WHT"歌舫凝梦音"NOR);
		set("nickname",MAG"秦淮月下晨昏舞"NOR);
        set("gender", "女性" );
		set("class","baiyun");

		set("age",33);
		set("per",37);

		set("no_busy",2);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );


        set_skill("unarmed", 250);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);
        set_skill("stormdance", 200);
        set_skill("kaleidostrike", 200);
        set_skill("force", 220);
        set_skill("snowforce", 220);


         map_skill("force", "snowforce");
		 map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "kaleidostrike");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "stormdance");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("透明纱衣", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/obj/music/qixianqin");
		weapon->set_name("半弦筝", ({"ting" }) );
		weapon->set("long","");
		weapon->set("value",0);
}

void smart_fight()
{

	if (query("ac")+ 30 <time())
	{
		ccommand("conjure guanglingsan");
		if (is_busy()) {
			set("ac",time());
			return;	
		}
	}
	
	if (query("ab")+ 10 <time())
	{
		ccommand("conjure bihai");
		if (is_busy()) {
			set("ab",time());
			return;	
		}
	}
	
}



/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

