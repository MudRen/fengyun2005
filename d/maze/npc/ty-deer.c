#include <ansi.h>;
inherit NPC;

void create()
{
		set_name("小鹿", ({ "little deer", "deer"}) );
    	set("race", "家畜");
    	set("age", 5);
    	set("long", "一头浅浅茸毛身上带着白色斑点的小鹿。\n");
    	set_skill("dodge", 100);
		set("target_name","小鹿");
		set("maze","taoyuan");
		set("chat_chance",1);
    		set("chat_msg",({
		(: random_move() :),
    	}) );  
	
		set("combat_exp", 50000);
		set("self_go_msg",1);
		set("arrive_msg","小鹿蹦蹦跳跳地跑了过来。");
		set("leave_msg","小鹿蹦蹦跳跳地跑走了。");
		set("env/wimpy",99);
		setup();
}