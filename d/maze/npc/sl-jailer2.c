#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void throw_away(object ob);

void create()
{
	set_name("伏虎尊者",({"fuhu monk","monk"}));
    	set("title","少林寺 罗汉");
    	set("long", "少林一百零八罗汉之次席。。\n");

	set("age",60);
	set("combat_exp", 5500000);
	set("attitude","friendly");
	set("group","shaolin");
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) ); 		

	auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","fumostaff",1);
		
	setup();
    	carry_object(__DIR__"obj/sl-key");
    	carry_object("/obj/armor/cloth",([	"name": "少林罗汉服",
					"long": "少林罗汉的僧衣。\n",
					 ]))->wear();  

}

void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object *inv;
	string my_position;
	if( !ob || environment(ob) != environment()) return;
	message_vision(YEL"伏虎尊者合掌唱了个诺道：施主，帝释天殿乃我少林圣地，再不速离，
恕伏虎降龙得罪了！ \n\n"NOR,ob);
	call_out("throw_away",10,ob);
	
}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	message_vision(YEL"伏虎尊者冷哼一声道：少林开山以来，就没有人能在这里撒野！ \n"NOR,ob);
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}

