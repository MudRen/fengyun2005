// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();
void smart_sleep();

void create()
{
	object weapon;
	set_name("方十三", ({ "fang shisan", "fang","shisan" }) );
	set("class","beggar");
	set("gender", "男性" );

	set("age", 25);

	set("force_factor",30);

	set("attitude", "friendly");
	set("long","趴在桌上呼呼大睡。你认了半晌，才认出他就是米人钱庄的三\n掌柜、江湖上人称「狗急跳墙」方十三！\n");

	set("nickname",MAG"狗急跳墙"NOR);
	set("title","米人钱庄"NOR);

	set("inquiry",([
       	"*": 	"呼呼呼．．．呼呼呼．．．ＺＺＺｚｚｚ．．．",
    	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
//		   (: smart_sleep() :),
	"方十三的呼噜打得震天响。\n",
	}) );

	set("no_arrest",1);

	set_temp("condition_type",YEL" <呼呼大睡中>"NOR);

	set("combat_exp", 4400000);

	set_skill("dodge", 400);
	set_skill("doggiesteps", 400);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	

	map_skill("dodge", "doggiesteps");
	setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("十三裙", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("方布帽", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();


}

void init()
{
	if (!is_fighting())
		set_temp("condition_type",NOR YEL" <呼呼大睡中>"NOR);
}

int kill_ob(object who)
{
	if (query_temp("condition_type"))
	{
		delete_temp("condition_type");
		ccommand("wake");
		ccommand("hmm "+who->query("id"));
		ccommand("say 我在睡觉，不要吵！");
	}
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();

	ccommand("perform dodge.goujitiaoqiang");

	if (!is_fighting())
	{
		message_vision(CYN"\n方十三打了个呵欠，趴回桌上，很快又沉入梦乡。\n"NOR,me);
		set_temp("condition_type",NOR YEL" <呼呼大睡中>"NOR);
	}

}


void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("kick "+who->query("id"));
	if (!is_fighting())
	{
		message_vision(CYN"\n方十三打了个呵欠，趴回桌上，很快又沉入梦乡。\n"NOR,who);
		set_temp("condition_type",NOR YEL" <呼呼大睡中>"NOR);
	}
}
