#include <ansi.h>
inherit NPC;

void create()
{
	set_name("拓跋战", ({"tuoba zhan","tuoba"}) );
        set("gender", "男性" );
        set("nickname", HIY"战狼"NOR);
        set("long", "这是一位彪悍勇猛，悍不畏死的战狼弟子。\n");
 	set("attitude", "friendly");
/*	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500); */
	set("age", 18+random(10));

        set("combat_exp", random(200000)+200000);
        create_family("狼山", 1, "第四代弟子");
        set_skill("blade", 100+random(20));
        set_skill("parry", 100+random(20));
        set_skill("dodge", 100+random(20));
        set_skill("move", 100+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        "拓跋战仰天长嚎：说英雄，谁是英雄？江湖虽大，不还是我狼山称雄！\n",
        }) );

        setup();
     	carry_object(__DIR__"obj/pifeng")->wear();
	carry_object(__DIR__"obj/wolfblade")->wield();  

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

void win_enemy(object loser)
{
	command("laugh");
    message_vision("$N对着$n摇摇头道：就这种身手还出来混，哈哈，笑掉老子大牙了！\n", this_object(), loser);
	return;
}

void lose_enemy( object winner )
{
	command("admire");
    message_vision("$N拍拍$n的肩膀道：不错不错，俺们大哥铁战跟你肯定一见如故。\n", this_object(), winner);
}

int accept_fight(object me)
{
	command("say 来呀，来呀！我正手痒痒呢！\n");
	return 1;
}

void greeting(object ob)
{   
	if (random(100)>30)
	{	
        message_vision("$N拍拍你的肩膀道：没有三两三，休想上狼山！先跟我比划比划吧。\n", this_object() );
      		return;
      	}
      	else if(ob->query("class")=="wolfmount")
      	{
            message_vision("$N一看到你兴奋地直嚷嚷：总算来了个过招的伴啦！\n", this_object() );
      		command("fight "+ob->query("id"));
		return;
	}
	return;
}
