#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("吕凤先",({"lu fengxian","lu"}));
		set("title",HIC"银戟温侯"NOR);
        set("long",WHT"
一个白面高冠的男子，修长的剑眉挑入双鬓，虽然浑身未有片缕，但依然看上去
儒雅高傲，气度不凡，似乎天下的威风都被一人占尽。\n"NOR);
     	set("gender","男性");
    	set("class","fugui");
    	set("combat_exp",900000);  
    	set("age",42);
    	   	
    	auto_npc_setup("liaoyin",120,120,0,"/obj/weapon/","fighter_w","xuezhan-spear",1);    	    	    		
		set_skill("perception",200);
		setup();
    	carry_object(__DIR__"obj/silver_spear")->wield();
}


void	die(){
	object cloth;
	object me, owner;
        if (this_object()->query("die")) {
        	::die();
        	return;
        }
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if (me && REWARD_D->riddle_check(me,"初探金钱")==1)
        	REWARD_D->riddle_set(me,"初探金钱",2);
	
        if (!this_object()->query("in_talk")) {
        	environment(this_object())->event2(me,0);
        	this_object()->set("in_talk",1);
        	start_busy(20);
        	me->start_busy(1000);
        }
}



void 	unconcious(){
	die();
}

