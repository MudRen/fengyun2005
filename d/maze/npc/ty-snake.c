#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIW"白花蛇"NOR, ({ "white snake","snake" }) );
        set("race", "蛇类");
        set("target_name","白花蛇");
        set("age", 1);
        set("long", "
这种蛇又名蕲蛇，产于湖蜀，但吸取了桃花林的毒瘴后的白花蛇，通体隐现粉色， 
极喜嗜人，歹毒异常。 \n");

		set("maze","taoyuan");
	
        set("group","snake");
        
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			WHT"白花蛇碧绿色的眼一闪一闪，血色的蛇信咝咝做响。\n"NOR,
    	}) );  
       
		set("combat_exp",400000);
        set_skill("dodge", 400);
        set_temp("apply/attack",200);
        setup();
}


int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(WHT"白花蛇象一支离弦之箭般突然直挺挺咬向$N的脖子。\n"NOR,target);
		tell_object(target,HIB"你哎呦一声，脖子上已是两个深深的毒牙印。\n"NOR);
		target->receive_damage("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
}
