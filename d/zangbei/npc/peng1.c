#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("屠城",({"tu cheng"}));
	set("title",WHT"十二飞鹏帮  大鹏"NOR);
   	set("long","万鹏王手下十二飞鹏帮的四大帮主之一。\n");
   	
     	set("gender","男性");
     	set("group","khlr");
     	
    	set("age",62); 	 	
    	    	
    	set("combat_exp",10000000);  
    	set("attitude", "friendly");
    	
    	set("boss",1);
    	set("resistance/kee",99);
    	set("resistance/gin",99);
    	set("resistance/sen",99);
    	set("NO_KILL","你被锦衣大汉的气势所摄，竟不敢出招。\n");
    	set("inquiry", ([
 
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,1,"/obj/weapon/","fighter_w","bat-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

void init(){
	::init();
	add_action("do_answer","answer");
}

int do_ask(object me){
	message_vision(CYN"
屠大鹏眼睛就像根鞭子正上上下下地抽打着$N，过了很久才道：“你认得韩棠？”\n"NOR,me);
	tell_object(me,WHT"\nanswer yes/no\n"NOR);
	me->set_temp("juyuan_tucheng",1);
	me->start_busy(8);	
	call_out("kill_him",10,me);
	return 1;
}

int kill_han(object ob){
	
	object peng1, peng2, peng3, peng4;
	
	peng1 = this_object();
	if (peng2=present("luo jiang",environment(peng1))) 
		peng2->kill_ob(ob);
	if (peng3=present("xiao an",environment(peng1))) 
		peng3->kill_ob(ob);
	if (peng4=present("yuan chong",environment(peng1))) 
		peng4->kill_ob(ob);
	peng1->kill_b(ob);
	return 1;	
}

int disappear(){
	object *inv;
	int i;
	message_vision("\n只听唿哨一声，锦衣大汉们消失在黑暗里。\n",this_object());
	inv = all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("khlr") && inv[i]!=this_object()) 
			destruct(inv[i]);
	}
	destruct(this_object());
	return 1;
}
	
int kill_him(object me) {
	
	object han,peng1;
	peng1 = this_object();
	han = present("han tang",environment(peng1));
	if (environment(me)!=environment(this_object())
		|| !objectp(han)) {
		disappear();
		return 1;
	}
	if (me->query_temp("juyuan_tucheng")) {
		message_vision(CYN"
屠大鹏叹了口气说，你既然不愿回答，我也不勉强。\n"NOR,me);
		me->delete_temp("juyuan_tucheng");
	}
	message_vision(CYN"
屠大鹏手里的刀锋突然向$N刺来，锐利的刀锋刺入$N的胸膛时仿佛鱼滑入水，
平滑而顺利。$N甚至完全没有感到痛苦。

$N大叫着向后跌倒，突又在半空扭转抽动，跌下时，脸扑在地，\n"NOR,me);
	me->delete_temp("juyuan_tucheng");
	me->unconcious();
	kill_han(han);
	return 1;
}



int do_answer(string arg){
	object me,han,peng1;
	peng1 = this_object();
	me = this_player();	
	han = present("han tang",environment(peng1));
	remove_call_out("kill_him");	
	if (!me->query_temp("juyuan_tucheng"))	return 0;
	
	if (!arg || (arg !="yes" && arg !="no"))
		return notify_fail("answer yes/no \n");
		
	if (arg == "yes") {
		message_vision(YEL"
$N一挺胸说：我是老伯的人，韩棠是菊园的人，你们统统滚出去！\n"NOR,me);
		message_vision(CYN"
屠大鹏说：很好，你们都可以去死了。\n"NOR,me);
		REWARD_D->riddle_set(me,"菊园传奇",6);
//		me->set("marks/kuaihuo/韩棠",1);
		
	}	
	if (arg =="no") {
		message_vision(CYN"
屠大鹏说：很好，你可以走了。\n"NOR,me);
//		me->set("marks/kuaihuo/韩棠",2);
		REWARD_D->riddle_set(me,"菊园传奇",7);
	}
	me->delete_temp("juyuan_tucheng");
	kill_him(me);
	return 1;
}


