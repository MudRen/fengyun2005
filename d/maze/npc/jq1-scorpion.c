#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        string *name = ({BLU"蓝",MAG"紫",HIR"赤",HIG"粉"});
        set_name(name[random(sizeof(name))]+"蝎子"NOR, ({"evil scorpion","scorpion"}) );

        set("maze","jq1");
        set("gender", "女性" );
        set("title", "金钱帮 女俾");
        set("long", "
这是上官金虹的爱女上官小仙的座下女俾，虽然只是女子，但个个凶狠毒辣，加
之美色诱人，死在其手下的江湖人数不胜数。甜甜的笑颜下，谁又会想到是杀人
不见血的催命女鬼？\n");

 	set("attitude", "friendly");
	set("age", 18+random(10));
	
	set("target_name","蝎子");
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
     }) );
		
    set("combat_exp", 700000);
    setup();
	auto_npc_setup("liaoyin",100,140,1,"/obj/weapon/","fighter_w","nine-moon-sword",1);
	delete_temp("nine-moon-force_poison");
	carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
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
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
		
	if ((string)ob->query("gender") == "男性")
	{
        message_vision("$N媚眼如丝盯着$n，洁白粉嫩的手摩挲着你的面庞，梦呓般道：来呀，我等你。。好久了。。。\n", this_object(),ob );
// here should add to cause ppl be poisoned, which not very lethom.
        if ((int)ob->query_cps()<random(25) && !ob->query_condition("no_shadow") ){
   			message_vision("$N心神一荡，迷迷糊糊，只觉得脸上一麻，愈来愈痒起来。\n", ob);
   			ob->apply_condition("no_shadow",random(5)+5);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$N冷笑一声：雕虫小技，怎能伤我！\n", ob);
	  		return;
	  	}
	  }
	  return;
}

