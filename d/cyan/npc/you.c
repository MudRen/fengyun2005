// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("游戏狂", ({ "master you","master","you" }) );
	    create_family("东海夷洲", 4, "五院长");
		set("class","taiwanese");

		set("nickname",HIG"疯狂的"NOR);
        set("gender", "男性" );

		set("age",47);
        set("long","东海夷洲除正副岛主外下分伍院，游戏狂就是其中一院院长。\n");

		set("chat_chance",3);
		set("chat_msg", ({
			"游戏狂摸着头骂道：格老子的，谁用东西丢偶？\n",
			"游戏狂瞪了你一眼道：香蕉你个芭乐，看虾米？\n",
		}) );
        set("inquiry",([
 			"老大"  :"老大都不知道？叫游戏疯！\n",
         ]) );

        set("combat_exp", 6100000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: ccommand("perform fentianzhan") :),
        }) );

		set_skill("blade",400);
		set_skill("beilongblade",240);
		map_skill("blade","beilongblade");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

		carry_object(__DIR__"obj/pxblade")->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("花衬衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("绿扁帽", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}



void attempt_apprentice(object me) {
	message_vision("$N对$n摇摇头：你先去见过我们老大再说。\n", this_object(),me);
}