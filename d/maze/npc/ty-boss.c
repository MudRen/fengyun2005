#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name("桃花雾妖", ({ "mist spirit","spirit" }) );
        set("race", "野兽");
        set("age", 231);
        set("long", MAG"
这是由花瘴毒气凝结而成的雾妖，仿佛一团粉色的烟雾，无形无体，但若是被其 
吞噬了，便连骨头都不会留下。。 \n"NOR);
        set("group","ghost");
		set("combat_exp",500000);
    	set("target_name","桃花雾妖");
	
        set("maze","taoyuan");
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
			(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		MAG"桃花雾妖有如一团烟雾般无声无息地在桃林中飘荡着。。\n"NOR,
    	}) );  

        set("NO_CORPSE",MAG"桃花雾妖一声惨叫，化成一股紫烟消失了，\n\t地上留下一滴晶莹的露珠。\n"NOR);
        
        set_skill("dodge", 600);
        set_temp("apply/attack",250);
        
        setup();
        carry_object(__DIR__"obj/ty-mist");
}

int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(MAG"桃花雾妖仿佛一团烟雾般把$N笼罩了起来，$N只觉一阵头晕目眩。\n"NOR,target);
		tell_object(target,HIB"你觉得昏昏欲睡。\n"NOR);
		target->receive_wound("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
}

