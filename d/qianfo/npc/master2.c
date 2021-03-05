// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();

void create()
{
    set_name("参机大师", ({ "master can", "master", "can" }) );
    set("long", "
参机大师是兴国大师的师弟，主管禅寺内院以及弟子出家剃度，
只有拜了参机大师，才算是真正入了禅寺修行。\n");
    	set("gender", "男性");
    	set("age", 74);
    	set("attitude", "peaceful");
    	set("class", "bonze");
    	set("apprentice_available", 3);
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	    	
	set("guard_msg",HIW"$N喝道：阿弥陀佛,出家人与世无争，却也不任人欺侮，施主请了！！\n"NOR);
    	set("combat_exp", 2000000);
    	set("score", 9000);

    	set("inquiry", ([
        	"剃度" : (: ask_for_join :),
        	"出家" : (: ask_for_join :),
        	"apprentice" : (: ask_for_join :),
        ]) );

    	set_skill("staff", 180);
    	set_skill("unarmed", 160);
    	set_skill("dabei-strike",150);
    	set_skill("force", 150);
    	set_skill("dodge", 150);
    	set_skill("literate", 150);
    	set_skill("chanting", 150);
    	set_skill("parry", 150);
    	set_skill("magic", 150);
	set_skill("cloudstaff", 150);
    	set_skill("lotusforce", 150);
    	set_skill("buddhism", 150);
    	set_skill("nodust-steps",150);
    	set_skill("essencemagic",150);
    	set_skill("perception", 100);
	set_skill("foreknowledge", 100);
 	set_skill("move", 150);
	
    	map_skill("staff", "cloudstaff");
    	map_skill("parry", "cloudstaff");
    	map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("magic","essencemagic");
    
     	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
    
    
    	create_family("兴国禅寺", 4, "住持");
		set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"小沙弥","小和尚","守山僧","布衣僧","麻衣僧","白衣僧","灰衣僧","黑衣僧",
		"护寺大师","护法罗汉","护国金刚","护寺神僧",YEL"护法圣僧"NOR,YEL"护国活佛"NOR,
		YEL"净土宗传人"NOR,HIY"净土宗宗主"NOR}));				
		
    	setup();
    	carry_object(__DIR__"obj/staff")->wield();
    	carry_object("/obj/armor/cloth")->wear();

}


string ask_for_join()
{
    	object me;

    	me = this_player();
	if (me->query("family/master_id")!="master dingbang"
		|| me->query("family/master_name") != "定邦大师"
		|| me->query("class") != "bonze") {
		command("shake");
		command("say 施主若想出家，先须在我师弟定邦处磨练几年，消些烟火之气。");
		return "\n";
	}
	
	if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
		command("shake");
		command("say 施主反复无常，没有向佛之心。\n");
		return "\n";
	}
 	if(me->query("marry") && !me->query("jiebai")){
		message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
				this_object(), me);
		return "\n";
	}	
    	
    	if( (string)me->query("gender") != "男性" )
        	return "阿弥陀佛！女施主，这里是寺庙，请你到尼庵去剃度吧。\n";
    	
    	if( (string)me->query("family/master_name")=="参机大师" || me->query("marks/剃度"))
        	return "阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？\n";
    	
    	if (me->query_skill("buddhism",1)< 100) 
    		return "阿弥陀佛！施主的大乘佛法修行还不到家（需１００级）。\n";

    	me->set_temp("pending/join_bonze", 1);
    	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
    	string *prename =
        	({ "空", "明", "圆", "净", "虚", "悟",
           		"方", "渡", "慧", "法" });
    	string name, new_name;

    	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
    	message_vision(
        	HIC "$N双手合十，恭恭敬敬地跪了下来。\n\n"
        	"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃下．\n\n"NOR,
        	this_player(), this_object() );
    	name = this_player()->query("name");
//    	new_name = prename[random(sizeof(prename))] + name[0..1];
//    	command("say 从今以後你的法名叫做" + new_name + "。");
    	command("smile");
    	this_player()->delete_temp("pending/join_bonze");
    	this_player()->delete_temp("pending/apprentice");
//    	this_player()->set("name", new_name);
    	this_player()->set("class", "bonze");
    	this_player()->set("marks/剃度",1);
    	return 1;
}

void attempt_apprentice(object me)
{
if (me->query("family/master_id")!="master dingbang"
		|| me->query("family/master_name") != "定邦大师"
		|| me->query("class") != "bonze") {
		command("shake");
		command("say 施主若想出家，先须在我师弟定邦处磨练几年，消些烟火之气。");
		return;
	}
	
	if (me->query("once_menpai/bonze") && me->query("class")!="bonze") {
		command("shake");
		command("say 施主反复无常，没有向佛之心。\n");
		return;
	}
   	if(me->query("marry")&& !me->query("jiebai")){
		message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。", 
				this_object(), me);
		return ;
	}	
    	
    	if( (string)me->query("gender") != "男性" ) {
        	command("say 阿弥陀佛！女施主，这里是寺庙，请你到尼庵去剃度吧。");
        	return;
        }
    	
    	if( (string)me->query("family/master_name")=="参机大师" ){
        	command("say 阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？");
        	return;
        }
    	
    	if (me->query_skill("buddhism",1)< 100) {
    		command("say 阿弥陀佛！施主的大乘佛法修行还不到家（需１００级）。");
    		return;
    	}

		if (!REWARD_D->check_m_success( me,"七彩缎带")){
			command("say 施主果然与佛门有缘，只是老僧有一心事未了。");
			command("say 兴国寺外有一游僧老实，名虽老实，实不老实，佛门清规，无一遵守。");
			command("say 近日来老实在寺门外屡屡与人斗殴，实扰我弟子清修。");
			command("say 你且去与他一试，让他知难而退就是了，万万不可伤他性命。");
			return;
		}
				
		if( !me->query("marks/剃度")) {
        	command("say 阿弥陀佛，施主果是信人，愿入佛门，请先剃度出家。");
        	return;
        }
        	
    	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + me->query("id") );
}

int accept_fight(object me)
{
    	if( (string)me->query("class")=="bonze" )
        	command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
    	else
        	command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");

    	return 0;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_kneel","kneel");

}

	
