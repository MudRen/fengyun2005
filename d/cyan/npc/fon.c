// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("风岚", ({ "feng lan","feng","lan" }) );
        set("title",HIG"风家三少"NOR);
		set("nickname",YEL"刀回星野无绝尽"NOR);
        set("gender", "男性" );
		set("class","moon");
		set("attitude", "friendly");


		set("age",21);

        set("long","一个正倚着石栏，默默沉思的少年公子。\n");

	set("chat_chance",8);
	set("chat_msg", ({
		"风岚望着天穹，默默地捻指推算。\n",
		"风岚叹道：果真是先人的智慧无穷，我遍访名山，竟再找不到比这里更好的观星之地。\n",
		"风岚看着指头，眉头紧皱，喃喃道：我有血光之灾？迫在眉睫？\n",
	}) );
        set("inquiry",([
 		"风满楼"  :"大哥？他整天带着二弟四处游荡，我也不知现在哪里。\n",
 		"风颜"  :"二弟？他整天跟着大哥四处游荡，我也不知现在哪里。\n",
              ]) );

        set("combat_exp", 5500000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform mingyue") :),
             }) );


        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);

        map_skill("blade", "chillblade");
        map_skill("parry", "chillblade");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N叹道：天相果然不曾骗我，天意，天意．．．\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("挂日刀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("墨色长衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		carry_object(__DIR__"obj/box");
}
