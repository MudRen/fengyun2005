// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int leave();
void create()
{
        set_name("卢定关", ({ "master lu", "master","lu" }) );
        set("long",
                "朝廷派驻在沉香的七品知县，进士出身，年轻有为，深得沉香百姓爱戴。\n");
		set("nickname", HIG"直宝章阁"NOR);
        set("attitude", "heroism");
        set("class","official");
        set("group","officer");
        set("rank_nogen",1);
        create_family("朝廷命官",7,"大理评事 知沉香县");
 
    	set("student_title","官员");
    	set("ranks",({ "准备将","副将","正将","副统领","统领","御营副统制",
                       "御营统制","御营都统制","龙神卫四厢都指挥使","捧日天武四厢都指挥使",
                       "侍卫亲军步军都虞候","侍卫亲军马军都虞候","殿前都虞候",
                       "侍卫亲军步军副指挥使","侍卫亲军马军副指挥使","殿前副指挥使",
                       CYN"侍卫亲军步军都指挥使"NOR,CYN"侍卫亲军马军都指挥使"NOR,HIC"殿前都指挥使"NOR }));
    	set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));    
   	set("inquiry", ([
		"leave": (: leave :),
	]) );
        set("combat_exp", 1000000);    
	set("vendetta_mark", "authority");
	set("reward_npc", 1);
	set("difficulty", 20);
        
	set("guard_msg",HIW"$N道：光天化日，朗朗乾坤，竟敢在衙门内狙杀朝廷官员，拿命来！\n"NOR);
	
		set_skill("unarmed", 100);
        set_skill("spear",100);
		set_skill("force",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("changquan",150);
		set_skill("puti-steps",100);
		set_skill("yue-spear",100);
        set_skill("manjianghong",100);
        set_skill("move", 100);
    	set_skill("leadership",100);
    	set_skill("strategy",100);
    	set_skill("literate",100);
    	set_skill("foreknowledge", 100);
    	
		map_skill("unarmed","changquan");
		map_skill("dodge","puti-steps");
        map_skill("force","manjianghong");
		map_skill("spear","yue-spear");
		map_skill("parry","yue-spear");
        
        set_temp("apply/damage",500);
        setup();
        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
		command("smile");
		command("say 很好！朝廷正在用人之时，努力吧！\n");
        	command("recruit " + me->query("id") );
	}
	else
		command("say 朝廷不需要你这种不三不四，来历不明之人！\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");
	}
}


void init()
{	
	::init();
	add_action("do_killing", "kill");
    
}


int leave() {
	if (this_player()->query("class")!="official") return 0;
	message_vision(CYN"$N正色道，“报效朝廷乃忠君爱民之事，怎么能半途而废呢。“\n"NOR, this_object());
	message_vision(CYN"$N说：若执意要走我也不勉强，只是从此就是一介平民，朝廷之事再也无权过问。\n"NOR,this_object());
	message_vision(CYN"$N说：玉环鸳鸯拳也不能再使，慎思，慎思。\n"NOR,this_object());
	return 1;
}

