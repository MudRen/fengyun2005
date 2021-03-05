#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;


int kill_him();

void create()
{
    	set_name("丁老四",({"ding laosi","ding","laosi"}));
		set("title","饭馆老板");
   		set("long","丁老四在这儿已经住了十五年了，虽然生意不好，勉强也能维持个生计。\n");
     	set("gender","男性");
    	set("age",52);
    	    	
    	set("combat_exp",1000000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
             	"江湖五毒"   :		(: kill_him :),
             	"青竹蛇"     :		(: kill_him :),
   		]));
    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

    	set("chat_chance",1);
    	set("chat_msg",({
		"丁老四道：“客官想吃什么尽管说，小店一定办到。”\n",
    	}) );    	    	
    	
        set("vendor_goods", ([
                __DIR__"obj/meal_1":	20,
                __DIR__"obj/meal_2":	20,
                __DIR__"obj/meal_3":	20,
                __DIR__"obj/meal_4":	20,
                __DIR__"obj/meal_5":	20,
        ]) );

    	auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","dragonstrike",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "灰布围裙",
    						"long": "一件半新不旧的灰布围裙，看来好久没洗过了。\n",
    						 ]))->wear();  
    
}

void init()
{	
//	object ob;
	::init();
	add_action("do_vendor_list", "list");
}

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"丁老四现在没空回答你。\n");
 		return 1;
 		}
 	if(!me->query("marks/wanma/棺材之谜")) {
        	tell_object(me,"丁老四说：没听说过，这名字邪气得紧。\n");
        	return 1;
        }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n"NOR,this_object());
        another = new(__DIR__"qingzhu");
	another->move(environment(this_object()));
        destruct(ob);
	return 1;
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/meal_1":	20,
                __DIR__"obj/meal_2":	20,
                __DIR__"obj/meal_3":	20,
                __DIR__"obj/meal_4":	20,
                __DIR__"obj/meal_5":	20,
        ]) );
}	