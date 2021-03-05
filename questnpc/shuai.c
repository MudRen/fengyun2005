//TIE@FY3
#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
void create()
{
	set_name("帅一凡", ({ "shuai yifan","shuai" }) );
	set("gender", "男性" );
        set("title","摘星羽士     气剑");
        set("nickname",HIG"一剑动三山 谈笑斩天星"NOR);
        set("quality","good");
	set("age", 55);
	set("int", 30);
	set("per", 30);
	set("fle",40);
	set("cps",35);
	set("dur",40);
        set("long",
"这个羽衣高冠的白发老者便是当年一剑动三山，力斩过天星的名侠。\n"
		);
        set("force_factor", 50);
        set("max_gin", 2800);
        set("max_kee", 3400);
        set("max_sen", 2800);
        set("eff_gin", 3000);
         set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);

        set("combat_exp", 10000000);
        set("score", 80000);
        set_skill("unarmed", 50);
        set_skill("sword", 220);
        set_skill("force", 90);
        set_skill("move", 270);
        set_skill("literate", 140);
	set_skill("dodge", 100);
	set_skill("siqi-sword", 150);
	set_skill("liuquan-steps", 100);
	set_skill("parry",140);
	map_skill("parry","siqi-sword");
    map_skill("sword", "siqi-sword");
    map_skill("dodge", "liuquan-steps");
	set("chat_chance",10);
	set("chat_msg",({
"帅一凡长长叹息了一声：“可惜故人们多已仙去，只剩下老朽百病之身，
还在人间流浪，再想找一个能伴我烹茶试剑的人，亦不可得了。”\n",
	})	);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
					(:perform_action,"dodge.liushuichanchan":),
        }) );

	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/qiushui")->wield();
}

