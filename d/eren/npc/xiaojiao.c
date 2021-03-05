#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("屠小娇",({"tu xiaojiao","tu","xiaojiao"}));
	set("age",20);
	set("gender","女性");
	set("long", "
一个明眸皓齿巧笑嫣然的绿衣少女。没有人知道她的真实身份，有人
说她是屠娇娇的弟子，也有人说她是屠娇娇的亲戚。\n");
	set("attitude", "friendly");
	set("combat_exp",5200000);
			
	set("reward_npc",2);
	
	set("inquiry", ([
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"屠小娇笑道：“客官请上楼歇息。”\n",
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );
	
	auto_npc_setup("guardian",200,200,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade",([	"name": "柳叶刀",
    						"long": "一把柳叶形的软刀，刀身细柔，没有一定的功力难以把握。。\n",
    						 ]))->wield();    
	
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
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	message_vision("$N姗姗走了过来，秋波向$n一瞟，万福道，“您好？”\n", this_object(),ob);
      	return;
}