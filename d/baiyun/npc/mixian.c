#include <ansi.h>
inherit NPC;
void create()
{
        set_name("迷仙", ({ "mi xian","mi" }) );
        set("gender", "女性" );
        set("title", "望仙乡 仙子");
        set("nickname",HIG"算等闲、酬一笑，便千金慵觑"NOR);
        set("age", 22);
        set("per", 30);
        set("long", "望仙乡三楼迷仙引的当家红倌人，婀娜多姿，风情万种，我见犹怜。\n");
        set("combat_exp", 350000);
        set("chat_chance", 1);
        set("chat_msg", ({
        	"迷仙幽幽地叹了口气，捂住心头，娥眉微蹙。\n",
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
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
		carry_object(__DIR__"obj/sinny4");
}


int accept_fight(object me)
{
        command("say 小女子若有怠慢，您可千万别介意，小女子给您作揖陪个不是。\n");
        return 0;
}
