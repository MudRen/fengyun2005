inherit SMART_NPC;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();
int kill_him();

void create()
{
        set_name("风道人", ({ "taoist feng","feng" }) );
        set("nickname",HIW "怒斧" NOR);
        set("title","三清供奉");
        set("gender", "男性");
        set("age", 60);
        set("long","风道人是丁氏兄妹从南疆请来的三清宫四供奉之一。\n");
        set("attitude", "friendly");
        set("combat_exp", 600000);
        set("score", 2000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("class", "knight");
       
		set("perform_busy_d", "knight/dodge/windy-steps/fengliu");
		set("perform_weapon_attack","knight/axe/xuanyuan-axe/guifushengong");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
        set("inquiry", ([
		         "内奸" : "action"CYN"“内奸？”风道人恶狠狠地瞪着你：“俺四供奉护着三清，哪里还有人敢当内奸？”\n"NOR,
                "三清道宗":  (: kill_him :),
        ]) );

        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("longlife-force",100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
        set_skill("axe",100);
        set_skill("xuanyuan-axe",90);
        set_skill("windy-steps",120);
        set_skill("flame-strike",100);
        map_skill("unarmed", "flame-strike");
        map_skill("force", "longlife-force");
        map_skill("axe","xuanyuan-axe");
        map_skill("dodge","windy-steps");
        map_skill("parry","xuanyuan-axe");
        map_skill("move","notracesnow");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();
        carry_object(__DIR__"obj/f_axe")->wield();
        carry_object(__DIR__"obj/f_cloth")->wear();
}


void init()
{       
        ::init();
        add_action("do_killing", "kill");
}

int do_killing(string arg)
{
        object player, victim;
        player = this_player();
        if(!arg || arg == "") return 0;
        victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
        if(living(victim))
        {
                if(victim->query("name")=="看风景的道姑" 
                        && victim->query("id")=="wandering taoist" )
                {
                        message_vision(HIW"$N对著$n喝道：大胆，是何居心!\n"NOR, this_object(), player);
                        this_object()->kill_ob(player);
                        player->kill_ob(this_object());
                        player->start_busy(2);
                        return 0;
                } 
        }
        return 0;
}

/*
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
//                              ccommand("say I will perform fengliu");
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                ccommand("smug");
                                this_object()->smart_attack();
                        } else ccommand("pig");
                }
        }
}

smart_busy() {
        this_object()->perform_action("dodge.fengliu");
}

smart_attack() {
        this_object()->perform_action("axe.guifushengong");     
        }
*/


int kill_him()
{
        object me;
        me = this_player();
        message_vision(CYN"$N冷冷的看了$n一眼，从鼻孔里哼了一声。\n"NOR,this_object(),me);
        command("say 你管的也太多了吧！\n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        me->perform_busy(2);
        return 1;
}

