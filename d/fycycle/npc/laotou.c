inherit NPC;
#include <ansi.h>
void create()
{
        set_name("胖老头", ({ "thin oldman","oldman" }) );
        set("gender", "男性" );
        set("title", WHT"骨瘦如柴"NOR );
        set("age", 62);
     
        set("long", "一个驼背弯腰的老头，须发皆已花白，但穿得却十分光亮花哨。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
     		"胖老头哼声道：笑甚么？他比武招亲，我尚未娶妻，难道我比不得？\n",
        }) );
        set("combat_exp", 20000);
        set("attitude", "friendly");
      
        set_skill("force", 60);
        set_skill("unarmed", 30);
        set_skill("dodge", 60);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


int accept_fight(object me)
{
        command("say 老夫一把老骨头，这位大侠别吓唬我。。\n");
        return 0;
}
