#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIR"红毛狐狸"NOR, ({ "red fox","fox" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", HIR"一只尖嘴的红毛狐狸，红色的皮毛如同火一般燃烧着，一双绿色的眸子凶光流露。。\n"NOR);
        
		set("target_name","红毛狐狸");
		set("pursuer",1);
		if (!random(5))	set("attitude", "aggressive");
        set("group","fox");
        set("maze","taoyuan");
            	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		RED"红毛狐狸眼露血光，直盯着你。\n"NOR,
    	}) );  
        
		set("combat_exp",350000);
        set_skill("dodge", 400);
        set_skill("move",400);
        set_temp("apply/attack",200);
        setup();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg == "red fox"){
		write("一只尖嘴的红毛狐狸，红色的皮毛如同火一般燃烧着，一双绿色的眸子凶光流露。\n");
		write("它看起来才出生几天。\n");
		write("它长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
		write("它精神饱满，正处于巅峰状态。\n");
		return 1;
	}
	return 0;
}

int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(name()+RED"猛地不顾一切扑了上来，$N只觉眼前一片红光，血光乍现。。\n"NOR,target);
		tell_object(target,HIR"你颈上一阵刺痛。\n"NOR);
		target->receive_damage("sen",target->query("max_sen")/20,ob);
		COMBAT_D->report_status(target);
		this_object()->start_busy(1);
	}
	return 1;
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}