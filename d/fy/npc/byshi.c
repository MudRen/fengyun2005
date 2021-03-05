// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("白云使", ({ "baiyun emissary", "emissary" }) );
        set("nickname", HIC"游剑江湖"NOR);
        set("gender", "男性" );
        set("class","baiyun");
        set("long","
白云使都是白云城中首屈一指的杰出一辈，被派遣到江湖上游历，没有实战
经验的人是永远不会成为真正的高手的。\n"
	);
	
        set("age", 24);
        set("per", 40);
        set("attitude","friendly");
        
        create_family("白云城",3, "剑使");
	set("rank_nogen",1);
    	set("ranks",({"琴使","棋使","书使","画使","剑士",CYN"剑使"NOR,CYN"剑师"NOR,HIC"大剑师"NOR}));
        
        set("combat_exp", 3000000);
        
        set("score", 20000);
    	set("reward_npc", 1);
	set("difficulty", 5);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "白云使微微一笑，拱手道：请。\n",
        }) );
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
        
        set_skill("move", 150);
        set_skill("daode",150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
        set_skill("sword", 150);
        set_skill("unarmed",150);
        set_skill("music",150);
        
        set_skill("feixian-steps",150);
        set_skill("feixian-sword",150);
        set_skill("calligraphy",150);
        set_skill("chessism",150);
        set_skill("magic",150);
        set_skill("painting",150);
        
        map_skill("magic","music");
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "chessism");
        map_skill("parry", "feixian-sword");

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();

}

void attempt_apprentice(object ob)
{
      	message_vision(CYN"白云使负手笑道：哈哈，白云定会成为天下第一剑派！\n"NOR, ob);
}

