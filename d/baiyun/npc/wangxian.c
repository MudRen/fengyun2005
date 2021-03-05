#include <ansi.h>
inherit NPC;
void create()
{
        set_name("望仙", ({ "wang xian","wang" }) );
        set("gender", "女性" );
        set("title", "望仙乡 仙子");
        set("nickname",HIM"一饷消凝，泪沾襟袖"NOR);
        set("age", 22);

        set("long", "望仙乡一楼的当家红倌人，婀娜多姿，风情万种，我见犹怜。\n");
        set("combat_exp", 270000);
        set("chat_chance", 1);
        set("chat_msg", ({
       		 "望仙噗嗤一笑，调皮地向你眨眨眼。\n",
		}) );
        set("attitude", "friendly");

        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("zhaixin-claw",70);
        set_skill("cloud-dance",80);
        set_skill("parry",90);
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","cloud-dance");
        
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
		carry_object(__DIR__"obj/sinny2");
}
int accept_fight(object me)
{
        command("say 小女子若有怠慢，您可千万别介意，小女子给您作揖陪个不是。\n");
        return 0;
}
