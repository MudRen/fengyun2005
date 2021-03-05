#include <ansi.h>

inherit SMART_NPC;
void create()
{

      set_name("侍卫统领", ({ "shiwei"}) );
	set("long", "这是一位蝙蝠岛专门担任巡逻之责的侍卫统领。\n");
      set("attitude", "aggressive");
      set("class","bat");
	
	set("no_arrest",1);
	set("combat_exp", 1000000);
	set_skill("bat-blade", 110);
	set_skill("blade", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("move", 120);
      	set_skill("meng-steps",100);
      	map_skill("dodge",   "meng-steps");
      	map_skill("parry"  , "bat-blade");
      	map_skill("blade"  , "bat-blade");
    	
    	set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	
	setup();

	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade",
    		([	"name"	:	RED"滴血刀"NOR,
    			"long"	: 	"这是一把充满邪气和杀机的钢刀。\n" ])
    		)->wield();
}

void init()
{
//      object ob;
        if( interactive(this_player()) && !is_fighting() && !random(3)&& this_player()->query("class")!="bat") {
 message_vision("\n$N忽然对$n阴森森一笑：敢闯到蝙蝠岛上来，活腻了么！\n",
this_object(),this_player());
	kill_ob(this_player());
        }
        ::init();
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
		} 
        if (me)
        if(me->query_temp("quicksand/route_bandit") == "蝙蝠岛")
        {
                me->set_temp("quicksand/route_notice",1);
                me->delete_temp("quicksand/route_bandit");
                tell_object(me,WHT"\n恭喜你平定了蝙蝠岛的匪患!\n"NOR);
                tell_object(me,WHT"你可以去告诉小潘这个好消息了。\n\n"NOR);
        }
        ::die();
}