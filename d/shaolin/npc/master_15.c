inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

int failit();
int dont();

void create()
{
    	set_name("天峰", ({ "master tian", "master"}) );
    	set("nickname", HIW "前任方丈"NOR);
    	set("gender", "男性" );
    	set("age", 94);
    	set("per", 25);
    
    	set("attitude","friendly");
    	      
    	set("long", "少林的第十五代方丈，因年事已高，隐居于此，他已经不管武林之事了。\n");
    	create_family("少林寺", 15, "大师");
    	set("class","shaolin");
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
    	    	"天峰低声道：你来的正好，一起品味品味这茶吧。。。\n",
            	"天峰叹道：这茶好香呀。。。\n"
        }) );
    
	    	set("inquiry", ([
        	"窃书": (: dont :),
        	"回报": (: failit :),
    	]));

    	set("reward_npc", 1);
    	set("difficulty", 10);    
    	set("combat_exp", 5000000);
    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","yizhichan",1);
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}


int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 5)  
	{
		ccommand("dunno "+me->query("id"));
		return 1;
	}
	ccommand("pat master tian");
	ccommand("emote 沉吟道：少林后经楼近日也不太平，莫非与此事有所牵连？");
	ccommand("say 这位施主请到后经楼一探，或能有所发现。");
	REWARD_D->riddle_set(me,"多事之秋",6);
	return 1;
}


int failit()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 7)  
	{
		ccommand("pure "+me->query("id"));
		return 1;
	}
	me->ccommand("emote 将事情始末详细地叙述了一遍。");
	ccommand("emote 手中的茶杯一颤，变色道：竟有此事？！");
	ccommand("emote 凝眉沉思：双手握的弧形长刀．．．双手握的弧形长刀．．．");
	ccommand("say 那不是．．．");
   	set_name(MAG"天峰"NOR, ({ "master tian", "master"}) );
	ccommand("emote "MAG"的脸色突然变得惨白，七窍中涌出紫黑色的鲜血．．．！！"NOR);
   	set_name(HIR"天峰"NOR, ({ "master tian", "master"}) );
	ccommand("emote "HIR"挣扎道：五．．．"NOR);
	REWARD_D->riddle_set(me,"多事之秋",8);
	if (present("master wu",environment()))
	{
		present("master wu",environment())->ccommand("emote 颤道：师父！！！！");
	}
   	set_name("天峰", ({ "master tian", "master"}) );
	tell_object(me,HIG"天峰大师既死，还有谁会知道"YEL"弧形长刀"HIG"的秘密呢？\n"NOR);
	die();
	return 1;
}


void attempt_apprentice(object me)
{
    	command("shake");
    	command("say 老衲年事已高，你还是去找方丈吧！\n");
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


