// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
int choice();
int do_answer(string arg);

void create()
{
    	set_name("心树", ({ "master shu", "master"}) );
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
        set("reward_npc", 1);
	set("difficulty", 10);
    
    	set("age", 64);

    	set("attitude","friendly");
        set("long", "少林寺七大高手之一。\n");
    	create_family("少林寺", 17, "大师");
    	set("student_title","长老");
    	set("class", "shaolin");
    	set("skill_public",1);
    	set("combat_exp", 7000000);
    
    	set("inquiry", ([
    		"请教" : (: choice :),
    		
    	]));
    	set_skill("move", 160);
	set_skill("dodge", 160);
	set_skill("force", 180);
	set_skill("unarmed", 180);
	set_skill("parry",160);
	set_skill("chanting", 160);
	set_skill("literate", 100);
	set_skill("zen", 160);
	         
	set_skill("puti-steps",150);
	set_skill("xiaochengforce",150);
	set_skill("dabei-strike",150);
	
	set_skill("fumostaff",170);
	set_skill("staff",200);
	
	map_skill("unarmed","dabei-strike");			
	map_skill("force","xiaochengforce");
	map_skill("dodge","puti-steps");
	map_skill("staff","fumostaff");
	map_skill("parry", "fumostaff");
    
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("perform_busy_w","shaolin/staff/fumostaff/hequhecong");

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
            
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
    	carry_object(__DIR__"obj/staff")->wield();

}

void attempt_apprentice(object me)
{
	message_vision(CYN"$N微笑不语。\n"NOR, this_object());
	return;
}

int choice()
{
	object me = this_player();
	
	if(me->query("family/family_name") != query("family/family_name") ||
	   	(me->query("family/master_name") != "心湖" && me->query("family/master_name")!="达摩面壁像"))
	 {
	 	message_vision(CYN"$N笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什麽？\n"NOR,this_object());
		return 1; 		
	 }
	
	if (me->query("marks/damoyuan3") == "xinshu"){
		message_vision(CYN"$N笑道：几日不见，师侄的佛学又有长进，来来，与老衲探讨探讨。\n"NOR,this_object());
		return 1;
	} 
				
	message_vision(CYN"
$N说道：金刚经有云：‘无我知，无人相，无众生相，无寿者相’。
老衲研习伏魔法已有四十二年，穷心极力，虽略有小成，只是在佛法
修为上，却及不上方丈师兄明心见性之无我之境，所谓禅道为本，武道
为辅。师侄既是方丈师兄所重，想必宿根深厚，大智大慧，老衲不敢为
师。若师侄有心，老衲可与你相互切磋。\n"NOR, this_object());
	tell_object(this_player(),"（达摩四僧，各有所长，你是否选择先向心树学艺？answer yes/no）\n");
	tell_object(this_player(),"（你可用skills来先看一下达摩四僧的武功）\n");
	this_player()->set_temp("answer/damoyuan3",1);
	return 1;
}
	
int do_answer(string arg)
{
	
	if ( !this_player()->query_temp("answer/damoyuan3"))
		return 0;
	
	if (arg == "no")
	{
		this_player()->delete_temp("answer/damoyuan3",1);
		message_vision(CYN"$N微微一笑，不再言语。\n"NOR, this_object());
	}
	else if (arg == "yes")
	{
		message_vision(CYN"$N说道：有心皆苦，无心即乐，老衲愿与师侄共勉。\n"NOR,this_object());
		this_player()->set("marks/damoyuan3","xinshu");
		this_player()->delete_temp("answer/damoyuan3",1);
	}else
		tell_object(this_player(),"你只能选择回答yes或者no。\n");
	
	return 1;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_answer", "answer");
}

int recognize_apprentice(object ob)
{
	if(ob->query("marks/damoyuan3") == "xinshu")
		return 1;        
}


int prevent_learn(object me, string skill)
{
     	int	betrayer, mylvl, lvl;

    	lvl = this_object()->query_skill(skill, 1);
    	mylvl = me->query_skill(skill, 1);
    	if( betrayer = me->query("betrayer") )
    	{
        	if( mylvl >= lvl - betrayer * 20 )
        	{
            	message_vision("$N神色间似乎对$n不是十分信任，\n"
                           "也许是想起$p从前背叛师门的事情\n...。\n",
                	           this_object(), me );
            	command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
            	return 1;
        	}
    	}
    	return 0;
}