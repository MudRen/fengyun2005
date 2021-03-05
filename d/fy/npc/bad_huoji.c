inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("贼眉鼠眼的伙计", ({ "suspicious huoji","huoji" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", "这个伙计一边往镖车上装载货物，一边东张西望。 \n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("class","bat");
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("bat-blade",100);
	set_skill("meng-steps",100);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("luoriquan",120);
	
	map_skill("dodge","meng-steps");
	map_skill("move","meng-steps");
	map_skill("blade","bat-blade");
	map_skill("parry","bat-blade");
	map_skill("unarmed","luoriquan");
	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
		
		set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		setup();
		
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/plan");
        
}

void init() {
//	object ob;
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
    object player, victim;
//  string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
       	if(victim == this_object())
        {
            message_vision(HIW"$N对著$n狞笑道：既然被你看出来了，你也别想活了!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            command("perform dodge.huanyinqianchong");
            return 0;
        } 
    }
    return 0;
}