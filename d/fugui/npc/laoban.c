// laoban.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("如意客栈老板", ({ "laoban" }) );
        set("long",
                "一个满脸堆笑的胖子。虽然他满脸笑容，你却觉得很不舒服。\n"
                );

        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 26);
        set("agi", 60);

        set("combat_exp", 10000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "如意客栈老板叹道：唉，吉祥镇这儿又是闹鬼，又是飞贼，这生意是\n越来越难做啊。\n",
                }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);

        setup();
        carry_object("/obj/armor/cloth")->wear();
}
