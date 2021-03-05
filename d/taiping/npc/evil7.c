#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{
        set_name("摩呼罗伽魔", ({ "evil" }) );
        set("title",HIR"十万神魔之"NOR);
        set("age", 400);
        set("long", "九天十地的妖魔，各式各样的妖魔。它们有的半人半兽，有的非人非兽，有的形状
是人，却不是人，有的形状是兽，却偏偏有一颗人心。风中，雾中，烈火中，寒冰
中，没有一处地方不看见这些妖魔。。\n");
        set("attitude", "aggressive");
 	set("combat_exp", 9000000);
	
	set("max_atman", 600);
	set("atman", 600);
	set("max_mana", 600);
	set("mana", 600);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",130);

	set("str",40);
	set("cor", 40);
	set("cps", 40);
	set("agi",40);
	set("fle",40);
	
	set("resistance/gin",30);
	set("resistance/kee",30);
	set("resistance/sen",30);
	set("statue",0);
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
	
	
	auto_npc_setup("xuebin",250,200,0,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	setup();
	carry_object(__DIR__"obj/maxe")->wield();
}




void die(){
	object me,owner,ob;
	
	ob=this_object();
	
	message_vision(HIR"\n一股黑烟腾起，$N化成一座石像,一动不动了。\n"NOR, this_object());
	ob->start_busy(10);
	ob->set("statue",1);
	call_out("reborn",20);
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	ob->set("resistance/kee",100);
	ob->set("resistance/gin",100);
	ob->set("resistance/sen",100);
	ob->remove_all_killer();
	
}

int reborn(){
	object ob;
	
	ob=this_object();
	message_vision(HIR"一转眼的功夫,黑烟凝聚，石像慢慢又活动起来。\n"NOR,ob);
	ob->set("resistance/kee",30);
	ob->set("resistance/gin",30);
	ob->set("resistance/sen",30);
	ob->set("statue",0);
	ob->stop_busy();
	ob->move(environment(ob));
	return 1;
}