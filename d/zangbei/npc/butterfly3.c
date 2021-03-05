#include <ansi.h>
inherit SMART_NPC;
int bite();
int patrol_move();

void create()
{
        set_name("高原绿蝶", ({ "butterfly" }) );
        set("race", "昆虫");
        set("age", 1);
        set("long", "美丽的蝴蝶，色彩绚烂，成群结队的在花丛中飞来飞去。\n");
        set("max_kee", 200);
        set("max_gin", 200);
        set("max_sen", 200);
        set("group","butterfly");
        set("str",10);
    	set("agi",20);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(: bite() :),
        ]) );  
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",2);
    	set("chat_msg",({
		"彩蝶一会儿向东，一会儿向西，在花丛中翩翩起舞。\n",
		(: patrol_move() :),
    	}) );  

		set("combat_exp",12000000);
        set_skill("dodge", 600);
        setup();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg && arg[0..8] == "butterfly"){
		if (!present(arg)) return 0;
		write("美丽的蝴蝶，色彩绚烂，成群结队地在花丛中飞来飞去。不过,世界
上越是美丽的东西，往往就越是危险。\n");
		write("它看起来才出生几天。\n");
		write("它长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
		write("它精神饱满，正处于巅峰状态。\n");
		return 1;
	}
	return 0;
}

int bite(){
	object ob/*,me*/,*enemy;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3))
	for (i=0;i<sizeof(enemy);i++) {
		message_vision(YEL""+name()+"扑闪着翅膀，阵阵花粉香味熏得人头昏脑胀，浑无斗志。\n"NOR,enemy[i]);
		tell_object(enemy[i],HIB"你觉得昏昏欲睡。\n"NOR);
		enemy[i]->receive_wound("sen",enemy[i]->query("max_sen")/20,ob);
		COMBAT_D->report_status(enemy[i]);
	}	
	this_object()->start_busy(1);
	return 1;
}

int patrol_move()
{
	mapping exits;
	string *dirs, direction, to_go_place/*, my_birth_place*/;
//	object env;
	string *patrol_route=({AREA_ZANGBEI"mroad1",AREA_ZANGBEI"mroad2",AREA_ZANGBEI"mroad3",
		AREA_ZANGBEI"erlang",AREA_ZANGBEI"garden1",AREA_ZANGBEI"garden2",AREA_ZANGBEI"garden3"});
	
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	
	dirs = keys (exits);
	direction = dirs[random(sizeof(dirs))];
	to_go_place = environment()->query("exits/"+direction);
		
	if (member_array(to_go_place,patrol_route)==-1) {
		return 1;
	}
	command("go " + direction);
	return 1;
}