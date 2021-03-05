// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;


void create()
{
		object weapon;
        set_name("歧路人", ({ "maze master","master" }) );
        set("long","一个满脸风尘的汉子，深邃的双眼紧紧地盯着你，你不禁倒吸一口冷气。\n");
        
        set("title",CYN"诸神殿 骑鹿"NOR);
        set("gender", "男性" );

		set("age",47);
		set("skill_public",1);

		set("chat_chance",1);
		set("chat_msg", ({
			"歧路人仰望天际，长叹道：骑鹿走歧路，路不平，鹿颠行，人心难安定。\n",
		}) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );

		set("inquiry",([
			"无有之术": CYN"去"WHT"明霞山"CYN"多走走看看吧。",
    	]) );

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

int prevent_shown(object me, string skill)
{
	if (skill == "pathfinding" || skill=="theorem")
		return 0;
	
	return 1;
}

int recognize_apprentice(object ob)
{
	object room2;
	
	if (F_LEVEL->get_level(ob->query("combat_exp"))<10){
		message_vision("歧路人摇头说，你的资历太浅，还学不了我的天路引归（至少需等级10）\n",ob);
		return 0;
	}
	
	if (ob->query("timer/mazemaster")+1830> time()) {
		message_vision("歧路人摇头说，你刚刚才来过，再等上"+ (ob->query("timer/mazemaster")+1800-time())/60+"分钟吧。\n",ob);
		return 1;
	}
	
	if (ob->query("quest"))
	{ 
		message_vision("歧路人摇头道：你现下俗事（quest）缠身，且去了断乾尽再来找我罢。\n\n",ob);
		return 0;
	}

	message_vision("歧路人微微一笑：要学天路引归么，好吧，那就看看你有没有本事找到我了！\n\n",ob);
	message_vision(WHT"歧路人稍一扬手，一阵烟气卷来，将$N"NOR+WHT"浸没其中。\n\n"NOR,ob);
	ob->set("timer/mazemaster",time());

		room2=find_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		if (room2)
		{
			room2->destruct_maze();
			room2=find_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		}
		if (!room2)
			room2=load_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		if (!room2)	
			room2="/obj/dungeon/maze"->query_maze_room(ob->query("id")+"/entry");

	ob->move(room2);
   	return notify_fail(" ");
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


