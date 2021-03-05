
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();

void create()
{
    	set_name("雪蕊儿", ({ "master xuerui", "master","xuerui" }) );
    	
    	set("gender", "女性" );
    	set("nickname", HIG "多情剑客"NOR);
    	set("long","
铁少从十五岁开始就和爱妻雪蕊儿行侠江湖，刀剑合壁，天下无敌。
正当两人名声鼎盛之时，忽然退出江湖，隐居于此。\n");

    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("boss", 1);
    	set("age", 26);
    	set("per", 30);
    	
 	set("group","legend");
 	set("couple","tiexue");
    	set("marry","master tieshao");
    
    	set("class","legend");	
    	set("apprentice_available", 50);
    	create_family("铁雪山庄", 1, "庄主夫人");
    	set("rank_nogen",1);
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"顽童","茶童","棋童","小侠","少侠","大侠",
    		"豪侠","奇侠","狂侠","情侠","侠圣","侠王",WHT"隐侠"NOR,
    		WHT"侠隐"NOR,WHT"气宗传人"NOR,HIW"气宗宗主"NOR}));
    	
    	set("inquiry", ([
        "leave" : (: leave :),
    	]));    
       
    	set_skill("force", 200);
    	set_skill("chanting", 180);
    	set_skill("parry", 170);
    	set_skill("dodge", 170);
    	
    	set_skill("perception", 150);
    	set_skill("move",150);
    	set_skill("unarmed", 160);
    	set_skill("sword", 250);
    	set_skill("literate", 100);
    	
    	set_skill("foreknowledge",100);      	
    	set_skill("six-sense",300);
    	set_skill("dormancy",300);
    	set_skill("meihua-shou", 150);
    	set_skill("diesword",200);
    	set_skill("qidaoforce", 150);
    	set_skill("fall-steps", 150);
    
    	map_skill("unarmed", "meihua-shou");
    	map_skill("sword","diesword");
    	map_skill("force", "qidaoforce");
    	map_skill("parry", "diesword");
    	map_skill("dodge", "fall-steps");

    	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
				(: perform_action, "sword.caidiekuangwu" :),	
        }) );

    	setup();
    	carry_object(__DIR__"obj/yellowcloth")->wear();
    	carry_object(__DIR__"obj/msword")->wield();
}


void reset()
{
       	set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
	        if( find_call_out("do_recruit") != -1 )
	            	command("say 慢著，一个一个来。");
	        else
	            	call_out("do_recruit", 2, ob);
    	} else {
        	command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
    	}
}

void do_recruit(object ob)
{
    	if( (string)ob->query("gender") != "女性" )
    	{      	
    		command("say 我只收女弟子，你还是去拜外子吧！");
    	}
    	else 
    	{
        	command("smile");
        	command("say 你日后必有大成！");
        	command("smile "+ ob->query("id"));
        	command("recruit " + ob->query("id") );
    	}
}


int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "legend");
    	add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
    	object xiaocui;
    	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    	{
        	command("smile");
        	command("say 还是让小翠来吧。");
        	return 0;
    	}
    	else
        	command("sigh");
    		command("雪蕊儿慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
    		command("say 请！");
    		remove_call_out("do_unwie");
    		call_out("do_unwie", 3);
    		return 1;
}

int do_unwie()
{
    	if( !this_object()->is_fighting()) 
    	{	
	        message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了铁少一眼，又坐在竹凳上。\n", this_object());
        	command("smile");
        	return 1;
    	}
    	else
        	call_out("do_unwie", 3);
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="legend") return 0;
	message_vision(CYN"$N道：人各有志，我不勉强你留下。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：只是聚气心法非弟子不能使用，蝶恋花剑法的精髓你大概也体会不到了。\n"NOR,this_object(),this_player());
	return 1;
}