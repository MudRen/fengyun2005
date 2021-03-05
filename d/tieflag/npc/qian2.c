inherit NPC;
#include <ansi.h>

void create()
{
        set_name("钱不要", ({ "qian buyao" }) );
        set("gender", "男性");
        set("age", 45);
        set("nickname","童叟无欺");
        set("long",
"圆圆的脸，矮矮胖胖的身材，说起话来笑嘻嘻的，右面脸上有个酒窝。\n"
);
	  
        set("attitude", "friendly");
        set("score", 0);
        set("reward_npc", 1);
	set("difficulty",5);
	set("class","wudang");
        
        set("combat_exp", 4400000);        
        
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
//            (: perform_action, "sword.chanzijue" :),
              (: perform_action, "unarmed.nianzijue" :),
        }) );

          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                        
        set_skill("taijiforce", 150);
	set_skill("five-steps",160);
	set_skill("taiji",180);
        
        
        map_skill("unarmed","taiji");
        map_skill("force", "taijiforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
	map_skill("parry","taiji");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

//        add_money("gold", random(5));
	carry_object("/obj/armor/cloth")->wear();
}

 
void init()
{
        object ob;
        ::init();
	add_action("do_killing","kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen;

    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");  
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "qian buzuan")
        {
            message_vision(
"$N笑道：咱兄弟俩总是一块儿上的。\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}