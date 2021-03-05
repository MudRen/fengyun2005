#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("毛战", ({"mao zhan","mao"}) );
    	set("gender", "男性" );
    	set("nickname", BLU"鬼头刀"NOR);
    	set("title", "青龙会 分舵护法");
    	set("long", "这人脸很长，象马的脸，脸上长满了粒粒豌豆般的疙瘩，眼睛里布满血丝。\n");
 	set("attitude", "friendly");
    	set("age", 35);
    	
	set("per", 6);
        set("combat_exp", 3000000);
    	set("class","assassin");
    	  	
    	set("reward_npc", 1);
        set("difficulty", 3);
        
        set_skill("unarmed",200);
        set_skill("dragonstrike",200);
        set_skill("blade", 200);
        set_skill("shenji-blade", 180);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("shenji-steps",180);
        
        map_skill("blade", "shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        map_skill("unarmed","dragonstrike");
        
		set("perform_busy_d", "npc/dodge/shenji-steps/shenjimiaosuan");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "毛战的马脸突然笑了起来，哈哈笑个不停：天底下竟然有\n这种傻瓜喜欢上一个侏儒瞎女人。。\n",
        }) );

        setup();
        carry_object(__DIR__"obj/duanblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !interactive(ob) || environment(ob) != environment() )
		return;
	if (!ob->query("vendetta/authority")){
            message_vision("$N嘿嘿道：够胆量！私闯青龙会的地头，拿命来吧！\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}

