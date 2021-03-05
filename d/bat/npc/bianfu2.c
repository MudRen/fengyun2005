#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
        set_name("七彩蝙蝠", ({ "colorful bat","bat" }) );
        set("race", "飞禽");
        
        set("age", 4);
        set("long", "一只浑身布满七彩的蝙蝠。\n");

        set("attitude", "aggressive");
        set_skill("dodge", 350+random(300));
        
        set("combat_exp", 800000+random(2000000));
		set("bellicosity", 3000 );
		set("agi", 15 );
        set("arrive_msg", "一声不响地飞过来");
        set("leave_msg", "一声不响地飞开了");
        
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
}

void use_poison()
{
        object *enemy, ob;
//      string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
		tell_object(ob,"七彩蝙蝠猛地冲下来，一口咬在你的脖颈上，你觉得一阵剧痛。。。。\n");
        ob->apply_condition("qicaibat",this_player()->query_condition("qicaibat")+ random(3)+20);
        return;
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}
