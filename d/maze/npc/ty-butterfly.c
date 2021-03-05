#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("花蝴蝶", ({ "butterfly" }) );
        set("race", "昆虫");
        set("age", 1);
        set("long", "一只硕大的粉色蝴蝶，暗红色躯体似乎隐隐流动着绿液。。\n");
        
        set("target_name","花蝴蝶");
            	
		set("maze","taoyuan");
	  	
    	set("chat_chance",1);
    	set("chat_msg",({
			"粉色蝴蝶忽然飞了起来，在桃花林中翩翩起舞。\n",
    	}) );  

        set("combat_exp",200000);
        set_skill("dodge", 300);
        set_temp("apply/attack",150);
        
        setup();
}


void die(){
	
	object *enemy;
	int n;
	
	enemy = this_object()->query_enemy();
	n = sizeof (enemy);
	message_vision(HIG"\n花蝴蝶扑地一声，化作一团绿雾。。。。\n"NOR,this_object());
	if (n)
	while (n--)  
		if (enemy[n]) {
			enemy[n]->receive_damage("sen",enemy[n]->query("max_kee")/20,this_object());
			COMBAT_D->report_status(enemy[n]);
		}
	::die();	
}