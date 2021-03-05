// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();


void create()
{
		object weapon;
        set_name("歧路人", ({ "maze master","master" }) );
        set("title",CYN"诸神殿 骑鹿"NOR);
        set("gender", "男性" );
		set("long","一个满脸风尘的汉子，此刻他正笑眯眯地看着你，似乎对你充满了信心。\n");

		set("age",47);
		set("NO_KILL","杀了你就永远地、永远地、永远地陷在这里了。。。。\n");
		set("skill_public",1);

		set("chat_chance",1);
		set("chat_msg", ({
			"歧路人仰望天际，长叹道：骑鹿走歧路，路不平，鹿颠行，人心难安定。\n",
			"歧路人说道：你可是想离开(Leavenow)了？\n",
		}) );

		set("inquiry",([
			"leavenow": (: leave :),
			"无有之术": CYN"去"WHT"明霞山"CYN"多走走看看吧。",
    	]) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
        }) );

        set_skill("sword", 400);
        set_skill("pathfinding", 200);
        set_skill("theorem",20);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 320);
        set_skill("13-sword", 220);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/armor/cloth");
		weapon->wear();

		carry_object("/obj/weapon/sword")->wield();

}

void init(){
	if (interactive(this_player())){
		ccommand("say 后生可畏，我这天路引归之术终于有了传人！");
		add_action("leave","leavenow");
	}
	return;
}

int prevent_shown(object me, string skill)
{
	if (skill == "pathfinding"|| skill=="theorem")
		return 0;
	
	return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill != "pathfinding"&& skill!="theorem")
  	{
      		command("emote 摇头叹道：人心难安定．．．");
      		return 1;
  	}
  	return 0;
}


int recognize_apprentice(object ob)
{
	return 1;
}


int leave()
{
	object me = this_player();
	object wer;
	
	if (me->is_busy()) {
		tell_object(me,"你现在正忙着呢。\n");
		return 1;
	}
	
	command("wave "+me->query("id"));
		
	wer = find_object("/d/fycycle/sroad5");
	if (!wer)
		wer = load_object("/d/fycycle/sroad5");
	me->move(wer);
    return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/



