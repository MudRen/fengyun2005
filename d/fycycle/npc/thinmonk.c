inherit NPC;
#include <ansi.h>
void create()
{
        set_name("瘦和尚", ({ "fat bonze","bonze" }) );
        set("gender", "男性" );
        set("title", YEL"肥头大耳"NOR );
        set("class", "bonze");
        set("age", 32);
        
        set("long", "一个光头和尚，满脸麻子，简直都分不出头顶的戒疤。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "瘦和尚嬉皮笑脸道：若是得了这样美貌的妻子，我和尚马上还俗。\n",
                }) );
        set("combat_exp", 500000);
        set("attitude", "friendly");
  
        set_skill("force", 60);
        set_skill("unarmed", 70);
        set_skill("iron-cloth", 50);
        set_skill("xisui", 40);
        set_skill("yizhichan", 80);
        set_skill("dodge", 60);
        
        map_skill("unarmed","yizhichan");
        map_skill("iron-cloth","xisui");
        
        setup();
        carry_object("/d/qianfo/npc/obj/cloth")->wear();
        carry_object("/d/qianfo/npc/obj/shoe")->wear();
}


int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
