// xiaojuan2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小娟", ({ "xiao juan","juan" }) );
	set("title", "民女");
	set("gender", "女性" );
	set("age", 16);
	set("str", 1);
	set("per", 30);
	set("long", @LONG
小娟姓刘，是这里刘老农的独生女。今年十六岁，人长的漂亮又大方。
可是她现在被淳于掠夺至此，已经被折磨的遍体鳞伤。
LONG
);
	set("no_heal",1);
	set("max_gin", 500);
	set("eff_gin", 1);
	set("gin", 1);
        set("max_kee", 500);
        set("eff_kee", 1);
        set("kee", 1);
        set("max_sen", 500);
        set("eff_sen", 1);
        set("sen", 1);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	
	set_skill("move",2000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		"小娟说道：唉！ 没料道你和那些坏人是一伙的！\n",
	}) );

	setup();
	carry_object(__DIR__"obj/torn_pink_cloth")->wear();
}


int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}


void init()
{
	object ob, room, liu;
	
	ob = this_player();
	room = find_object(AREA_CHUENYU"dungeon");
	if (environment(this_object())!= room || query_temp("following"))		
		return;
	else if (interactive(ob)) {
		remove_call_out("followhim");
		call_out("messageing",3);
		call_out("followhim", 20, ob);
	}
}

void messageing()
{
	object room;
	room = find_object(AREA_CHUENYU"dungeon");
	if(environment() == room) {
		command("say 救我！救救我呀！");
        	command("emote 竭力挣扎，渐渐从绳索里摆脱出来……。");
	}
}


void followhim(object ob) {
	object room;
	room = find_object(AREA_CHUENYU"dungeon");
    	if(environment() == room && objectp(ob) && interactive(ob) && present(ob, environment())) {
		set_leader(ob);
		set_temp("following",1);
		ob->set("marks/老刘", 1);
		message_vision(CYN"小娟从绳索中挣扎出来，惊恐地跑到你身后。\n"NOR,ob);
	}
}

void goaway()
{
	destruct(this_object());
}

void die()
{
	int i;
	object killer;

	if(objectp(killer = query_temp("last_damage_from")))
    	killer->set_temp("marks/xiaojuan_murder", 1);
	::die();

}

int heal_up()
{
	int count;
		
	if (query_temp("following") && query("count")<40) {
		add("count",1);
	}		
	else if(environment() && !is_fighting() && !is_busy()
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		delete("count");
		delete_temp("following");
		return_home(query("startroom"));
		return 1;
	}
		
	if (query("count")>30) {
		delete("count");
		delete_temp("following");
		if (file_name(environment()) != query("startroom"))
			return_home(query("startroom"));
		return 1;
	}
	
	return ::heal_up() + 1;
}