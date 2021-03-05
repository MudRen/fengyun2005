#include <ansi.h>
inherit NPC;

void create()
{
        set_name("幽怨妇人", ({ "sad woman","woman" }) );
        set("gender", "女性" );
        set("long",
                "一个愁眉苦脸，郁郁寡欢的妇人。\n"
                );
        set("title", WHT"天涯孤旅"NOR);
        set("attitude", "peaceful");
    	set("age", 25);
        set("per", 20);
        set("combat_exp", 1200000);
        
        set_temp("apply/damage", 50);

        set("chat_chance", 1);
        set("chat_msg", ({
                "幽怨妇人喃喃吟道：知否,知否，应是绿肥红瘦！\n",
                }) );

        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
    	set_skill("doomstrike", 100);
    	set_skill("doomsteps", 100);
    	
    	map_skill("unarmed", "doomstrike");
    	map_skill("dodge", "doomsteps");
        
        
        setup();
        carry_object("/d/qianfo/npc/obj/lady_dress")->wear();
}

