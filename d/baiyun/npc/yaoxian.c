#include <ansi.h>
inherit NPC;
void create()
{
        set_name("摇仙", ({ "yao xian","yao" }) );
        set("gender", "女性" );
        set("title", "望仙乡 仙子");
        set("nickname",HIR"为盟誓，今生断不孤鸳被。"NOR);
        set("age", 22);
        set("long", 
"望仙乡二楼摇仙佩的当家红倌人，婀娜多姿，风情万种，我见犹怜。\n");
        set("combat_exp", 280000);
        set("chat_chance", 1);
        set("chat_msg", ({
        	"摇仙轻抚瑶琴，曼声吟唱：细思算，奇葩艳卉，惟是深红浅白而已。\n",
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
        carry_object("/d/fugui/npc/obj/w_skirt4")->wear();
		carry_object(__DIR__"obj/sinny3");
}


int accept_fight(object me)
{
        command("say 小女子若有怠慢，您可千万别介意，小女子给您作揖陪个不是。\n");
        return 0;
}
