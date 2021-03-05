#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("大法师", ({"da fashi","fashi"}) );
        set("gender", "男性" );
  	set("class", "taoist");
        set("nickname", HIR"食人狼王"NOR);
        set("long", "
一个态度很严肃的老人，戴着顶圆盆般的斗签，一身血红的袈裟长垂
及地，雪白的胡子使得他看来更受人尊敬。\n");

 	set("attitude", "friendly");
 	set("reward_npc", 1);
	set("difficulty", 10);
        set("combat_exp", random(800000)+2500000);
        
	set("fly_target",1);
	set("age", 54);

        set("chat_chance", 1);
        set("chat_msg", ({
        	"大法师嘿嘿笑道：小姑娘的肉不但好吃，而且滋补得很。\n",
        }) );
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	
    	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","necromancy",1);
        setup();
        carry_object(BOOKS"cursism_50")->wear();
        carry_object(__DIR__"obj/hat")->wear();
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
	if (ob->query("gender") == "女性")
	{
		message_vision("$N流着口水，盯着$n：“细皮嫩肉的，胸脯一定很好吃。”\n", this_object(),ob );
		kill_ob(ob);
	}
	return;
}
