inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("黑影", ({ "master shadow", "master"}) );
        set("gender", "男性" );
        set("age", 64);
        set("per", 3);
        set("reward_npc", 1);
        set("difficulty", 25);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("attitude","friendly");
    
        set("combat_exp", 12000000);
        set("score", 200000);
        set("max_force", 5000);
        set("force", 5000);
        
        set("long","不知从何处来，不知道何处去．．．\n");
    
        create_family("魔教", 1, "执令使");
        set("rank_nogen",1);
        set("ranks",({"教徒","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老","大长老","副帮主"}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,15000000 }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight(90) :),
        }) );
        
        set_skill("whip", 300);
        set_skill("dragonwhip", 200);
        set_skill("unarmed", 200);
        set_skill("divineforce", 190);
        set_skill("spicyclaw", 170);
                set_skill("perception",200);
                set_skill("magic",200);
                set_skill("sheolmagic",200);
        set_skill("literate", 180);
        set_skill("chanting", 190);
        set_skill("dodge", 200);
        set_skill("move", 160);
        set_skill("parry", 200);

        map_skill("unarmed", "venusfinger");
        map_skill("force", "divineforce");
        map_skill("whip", "dragonwhip");
        map_skill("magic", "sheolmagic");

                set("no_kill",1);

        
        setup();
        carry_object(__DIR__"obj/fengwhip")->wield();

}

