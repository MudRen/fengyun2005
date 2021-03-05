#include <ansi.h>

inherit SMART_NPC;
void fight_now();

void create()
{

	set_name("无名",({"fighter"}));
   	set("title",YEL"燕云三十六骑"NOR);
	set("long", "这是探花楼用来愉悦客人的幻象，一般他都是傻站着被你杀。\n");
	set("age",30+random(20));
	set("group","trainer");
	set("combat_exp", 6500000);
		
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
			(: fight_now :),  	
    }) );
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void die() {
	command("say 死了，翘辫子了！");
	destruct(this_object());
}

void fight_now(){
	int num;
	num = query("fight_chance");
	auto_smart_fight(num);    
	return;
}

