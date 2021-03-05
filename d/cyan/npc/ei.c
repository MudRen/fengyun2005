// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("羽轻祈", ({ "yu qingdi","yu","qingqi" }) );
        set("title","明霞山 "HIB"飞琴"NOR);
		set("nickname",MAG"仰视云星织巧恨"NOR);
        set("gender", "女性" );
		set("class","moon");

		set("age",21);

        set("long","羽轻祈蹲坐在山道边，默默出神。\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"羽轻祈蹲坐在山道边，默默出神。\n",
		"羽轻祈微叹道：然而日子就这样流淌过去．．．\n",
		"羽轻祈似是陷入过往的回忆中，低低道：而那些以前说着永不分离的人，早已经散落在天涯了……\n",
	}) );
 
        set("combat_exp", 7000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
             }) );


		set("death_msg",CYN"\n$N凄楚一笑，慢慢合上眼睛。\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("化劫刀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dagger");
        weapon->set_name("长树枝", ({ "dagger" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("黄衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","spring-blade",4);
}
