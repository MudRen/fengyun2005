#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("铁萍姑",({"tie pinggu","pinggu"}));
	set("age",18);
	set("gender","女性");
	set("long", "
一个十七八岁的少女，虽然穿着农家衣饰，却掩不住绝美之色。可是，
她的眼角总带着淡淡的哀伤。\n");

	set("attitude", "friendly");
	set("combat_exp", 2000000);
	set("group","pinggu");		
	set("inquiry", ([
   		"李大嘴": "大嘴是我爹，我爹对我很好，最近他有事到泰山去了。",   		
   		"爹爹": "大嘴是我爹，我爹对我很好，最近他有事到泰山去了。",   
   	]));
	
	set("chat_chance", 1);
        set("chat_msg", ({
        	"铁萍姑说：“你见到我爹爹就叫他快回家吧。”\n",
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("guardian",150,150,1,"/obj/weapon/","fighter_w","three-sword",1);
	
	setup();
	carry_object(__DIR__"obj/pgcloth")->wear();
	
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
	if (REWARD_D->riddle_check(ob,"小村神医")==1) {
		message_vision(CYN"$N说：谢谢你救了黑蜘蛛，他让我转告你，此地人人心怀叵测，
唯神医万春流乃燕大侠故交，可托"YEL"重任"CYN"。\n"NOR, this_object(),ob);
      		REWARD_D->riddle_set(ob,"小村神医",2);
    }
    return;
}
