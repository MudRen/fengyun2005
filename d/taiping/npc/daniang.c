#include <ansi.h>
// RIDDLE NPC, shouldn't be in Questlist.

#include <command.h>
inherit SMART_NPC;

void create()
{

		set_name("李大娘",({"li daniang","daniang","li"}));
    	set("long", "
她的笑容如春花开放，语声如春莺婉转。身材比左右的女人更丰满，相貌也
更美。血奴已是罕见的美人，仍未能与她相比。她就随随便便地坐在那里，
已风情万种。\n");
		set("age",47);
		set("combat_exp", 10000000);
        set("attitude", "friendly");	
	
		set("reward_npc",20);

		set("group","lidaniang");
	
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
		auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","diesword",2);
		setup();
		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/lisword")->wield();
}


/*
void init() {
	
	object ob;
	::init();
	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	call_out("ask_question_1",1,ob);

}
*/

void die() {
	object me, ob, owner;
	ob=this_object();	
	message_vision(HIR"\n$N忽然发出一阵凄厉的笑声：十万神魔十万血，魔王还在，我是不会死的。\n"NOR,ob);
	message_vision(HIR"$N忽然急退，穿入了东面的屏风之后。屏风之后是面宽阔的照壁。$N转入
了屏风便不再出现。\n"NOR,ob);
	destruct(ob);
}

