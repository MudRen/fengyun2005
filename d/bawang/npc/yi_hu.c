#include <ansi.h>
inherit NPC;

void create()

{

        set_name("王一虎", ({ "wang yihu","yihu","wang"}) );
        set("title", "饿虎寨 二当家" );
        set("nickname", HIY"大力金刚"NOR);
        set("gender", "男性");
        set("age", 33);
	set("long",
		"一条彪形大汉。顾名思义，此人力大无穷。手里提著把开山大斧，一\n条腿就比陈准整个人都重。\n" );
        set("combat_exp", 600000);
        set("score", 17000);
	set("cor",30);
	set("attitude","killer");
        set("bellicosity", 600);
        
        set_skill("force", 100);
        set_skill("axe", 100);
        set_skill("parry", 120);
        set_skill("dodge", 120);
	set_skill("wuche-axe",120);
	set_skill("puti-steps",120);
	
	map_skill("axe", "wuche-axe");
	map_skill("parry","wuche-axe");
	map_skill("dodge","puti-steps");
	
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "axe.sanbanfu" :)
        }) );

        setup();

        carry_object(__DIR__"obj/huge_axe")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
//        add_money("gold", 1);
}



void init()

{

	object me;
	::init();
	me = this_player();
	if(interactive (me) && environment(me) == environment() && !me->is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}



void greeting(object me)

{
	if((string)me->name() !="老山东" && !me->query_temp("marks/keychain_ehg") ) 
	{
		command("say 来来来，让你看看老子的斧子有多快！\n");
		this_object()->kill_ob(me);
	}
	else
	{
		command("say 老山东，这次给老子带烧鸡了没有？\n");
	}
}

