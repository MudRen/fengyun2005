#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIY"九尾火貂"NOR, ({ "fire mink","mink" }) );
        set("race", "野兽");
        set("age", 21);
        set("long", HIY"
一只生了九条尾巴的火貂，赤色的精眸仿佛燃烧着两团火焰，四脚爪子锋利
异常，来回窜跃之间如同一道火线般迅捷异常。\n"NOR);
        
        set("target_name","九尾火貂");
        set("group","fox");   	
    	set("maze","taoyuan");
    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			HIY"火貂闪电一般蹿到树上，仿佛一团火飞来飞去。\n"NOR,
    	}) );  
        
		set("combat_exp",450000);
        
        set_skill("dodge", 500);
        set_temp("apply/attack",300);
        
        setup();
        carry_object(__DIR__"obj/ty-skin");
}


int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(name()+RED"如同一团火一般扑了上来，狠狠地朝$N的脸上咬了过来。\n"NOR,target);
		tell_object(target,HIR"你脸上一阵剧疼，伸手一摸，已是一排深深的牙印。\n"NOR);
		target->receive_damage("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		this_object()->start_busy(1);
	}
	return 1;
}
