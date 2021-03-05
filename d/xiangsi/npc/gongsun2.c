// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();
int look_stone();

void create()
{
	set_name("公孙太夫人", ({ "gongsun furen","gongsun","furen" }) );
	set("class","huashan");
	set("gender", "女性" );
	set("age", 45);

	set("attitude", "friendly");

	set("long","她自从第一次出手杀劳山掌门一雁道长于渤海之滨后，至今已
二十二年。根据武林中最有经验，最有资格的几位前辈的推测
和判断，她又曾出手过二十一次，平均每年一次，每次杀的都
是当今武林中的顶尖高手。\n"NOR);
	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"公孙太夫人慢慢的说：我要杀的人，就算他已经死了，我也会让他再活回来—次，然后再死在我手里。\n"NOR,
	}) );

	set("inquiry",([
       	"月神": 	"月神乃是当下价格最高的杀手，可惜老身遍访不得，无法一偿外子心愿。\n",
		"外子": "他是我的丈夫，他在他的家族里辈份很高，所以我才会被称为公孙太夫人。\n",
		"李坏": (: look_stone :),
    	]) );

	set("combat_exp", 1500000);

	set("reward_npc",1);
	set("difficulty",3);

	set_skill("move", 400);
	set_skill("dodge", 200);
	set_skill("parry", 100);
	set_skill("force",200);
	set_skill("staff",200);
	set_skill("illusionstick",300);
	set_skill("liangyi-force",200);
	set_skill("hanmei-force",200);
	map_skill("force","liangyi-force");
	map_skill("staff","illusionstick");
	map_skill("parry","illusionstick");
	
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
        	 (: smart_fight() :),
	}) );

	setup();

	carry_object(__DIR__"obj/robe2")->wear();
	carry_object(__DIR__"obj/stick");

}


int kill_ob(object who)
{
	ccommand("wield all");
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	set("force",4000);
	ccommand("perform menghuantianluo");
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("sigh2 "+who->query("id"));
	if (!is_fighting())
		ccommand("unwield all");
}


void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (me )
	{
		if (REWARD_D->riddle_check(me,"两世恩怨") == 6 && me->query_temp("annie/riddle/moonmaster") == 9)
		{
			message_vision(CYN"\n公孙太夫人顿住脚步，叹道：长江后浪推前浪，如今的天下，已经是你们的世界了．．．\n公孙太夫人说道：李坏便在旧日冷香楼中。想要见他，你就去找外子吧。\n公孙太夫人摇了摇满是银发的头，慢慢踱开。\n\n"NOR,me);
			REWARD_D->riddle_set(me,"两世恩怨",7);
			destruct(this_object());
			return;
		}
	}
	::die();
}

int look_stone()
{
	object me;
	me=this_player();

	if (REWARD_D->riddle_check(me,"两世恩怨") == 6 )
	{
		ccommand("hmm");
		ccommand("say 想见李坏，先拿出你的本事再说！");
		me->set_temp("annie/riddle/moonmaster",9);
		kill_ob(me);
		return 1;
	}
	message_vision("$N说道：李坏是小李飞刀传人，铁银衣老儿曾经提过。\n"NOR,this_object(),this_player());
    return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
