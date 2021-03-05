
#include <ansi.h>

inherit SMART_NPC;
void create()
{

    	set_name("巡逻侍卫", ({ "xunluo shiwei", "shiwei"}) );
	set("long", "这是一位蝙蝠岛专门担任巡逻之责的侍卫。\n");
   	set("attitude", "aggressive");
   	set("class","bat");

      	set("chat_chance", 85);
      	set("chat_msg", ({
        	(: random_move :),
      	}) );

	set("combat_exp", 800000);
	
	set_skill("bat-blade", 80+random(100));
	set_skill("blade", 80+random(100));
	set_skill("parry", 80+random(100));
	set_skill("dodge", 80+random(100));
	set_skill("move", 80+random(100));
      	set_skill("meng-steps",100);
      	set_skill("move", 80 + random(100));
      	
      	map_skill("dodge",   "meng-steps");
      	map_skill("parry"  , "bat-blade");
      	map_skill("blade"  , "bat-blade");
      	map_skill("move",    "meng-steps");
      	
		set("perform_busy_u", "bat/dodge/meng-steps/huanyinqianchong");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

	setup();

	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/bblade")->wield();
}


void init()
{
        object ob;
        if( interactive(this_player()) && !is_fighting() && !random(3)&& this_player()->query("class")!="bat") {
 		message_vision("\n$N忽然对$n阴森森一笑：敢闯到蝙蝠岛上来，活腻了么！\n",this_object(),this_player());
		kill_ob(this_player());
        }
        ::init();
}
