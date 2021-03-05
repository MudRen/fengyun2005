
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("雀子鹤", ({ "zihe" }) );
        set("gender", "男性" );
        set("age", 35);
	set("title", HIW "双掌翻天"NOR);
        set("attitude", "peaceful");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
		"雀子鹤喃喃道：楚留香呀，楚留香！看你这此往哪里逃！\n",
        }) );

        set("long",     "江湖中人称＂双掌翻天＂的雀子鹤\n");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "dodge.liushuichanchan" :)

        }) );
        set("combat_exp", 299999);
        set_skill("unarmed", 120);
	set_skill("dodge", 100);
        set_skill("yunwu-strike", 80);
        set_skill("liuquan-steps", 70);

        map_skill("unarmed", "yunwu-strike");
        map_skill("dodge", "liuquan-steps");

        setup();
        carry_object("/obj/armor/cloth")->wear();
}
