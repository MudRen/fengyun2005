#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void throw_away(object ob);

void create()
{

	set_name("谢小玉",({"xie xiaoyu","xie","xiaoyu"}));
    	set("title",HIG"神剑山庄"NOR);
    	set("long", "
谢小玉给人的印象绝对是尊女神。她在白纱隐约中暴露了所有的女性的特征，只不
过那是一种美感、一种神圣而庄严的美感，仿佛她全身都发着一股圣洁的光，使人
不敢逼视。使人愿意奉献一切，成为神前的牺牲。\n");

	set("gender","女性");
	set("age",20);
	set("combat_exp", 7500000);
	set("class","swordsman");        	
	set("attitude","friendly");
	set("reward_npc",10);
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) ); 		
		set("smartnpc_busy",1);
	
	auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","softsword",1);
		
	setup();
	carry_object("obj/armor/cloth")->wear();
	carry_object("obj/weapon/sword",([	"name": "七星绝命剑",
    						"long": "一把三尺长的软剑。剑刃上嵌着七颗星状的暗器。\n",
    						"value": 2,
    						"damage": 70,
    						"level_required": 100,
    						 ]))->wield();    

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
	
//	object *inv;
//	string my_position;
	if( !ob || environment(ob) != environment()) return;
	command("say 你怎么会闯到这里来的？快出去！否则就没机会了。");
	call_out("throw_away",10,ob);
}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}	