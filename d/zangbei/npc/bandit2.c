#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("马贼",({"bandit"}));
	set("long", "这是一伙专门打劫行商的马贼。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1500000);
	set("group","bandit");
		
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("guardian",150,125,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();
}


void init() {
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() ) return;
	
	if (ob->query("gender")=="女性") {
		switch (random(3)) {
			case 0: message_vision(CYN"$N对着$n叫道：美人，留下跟着大爷吃香喝辣吧！\n"NOR,this_object(),ob);
				break;
			case 1: command("rose "+ob->query("id"));
				break;
			default: command("qmarry "+ob->query("id"));
		}
		return;
	}
	else if (ob->query("combat_exp")<2500000){
		message_vision(CYN"$N叫道：劫财不伤命，识相的就把金子留下，大爷放你一点生路！\n"NOR,this_object());
		kill_ob(ob);
	}
	else
		command("say 大爷随便走，随便看，呵呵。");
}


void die(){
	
	object *inv;
	int i, friend;
	
	inv = all_inventory(environment());
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==this_object()) continue;
		if (inv[i]->query("group")=="bandit")	friend =1;
	}

	if (friend) {
		message_vision(CYN"$N大叫一声：不好，点子扎手，我去报信，你顶着！\n"NOR,this_object());
		message_vision("$N一溜烟地往废墟背后跑掉了。\n",this_object());
		destruct(this_object());	
		return ;
	}
	
	::die();    
}
