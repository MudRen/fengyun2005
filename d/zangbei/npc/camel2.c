inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("单峰雌驼", ({ "female camel","camel" }) );
	set("race", "家畜");
	set("gender", "雌性");
	set("age", 3);
    	set("long", "一匹大漠中常见的单峰骆驼，正在湖边歇息。\n");

	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		CYN"雌骆驼将头在雄骆驼的身侧蹭了几下，很亲密的样子。\n"NOR,
        }) );
        set("combat_exp", 2000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
	carry_object(__DIR__"obj/an")->wear();
}


void	die_next(){
	object ob=this_object();
	call_out("die_next_2",6,ob);
	
}

void 	die_next_2(object ob) {
	if (objectp(ob) && ob)
		message_vision(HIR"\n雌驼前膝跪下，对着雄驼的尸体发出凄惨的嘶鸣声，眼框中似乎有泪流下。。\n"NOR,ob);
	die();
}