#include <ansi.h>

inherit NPC;
void create()
{

        set_name("岳鳞", ({"yue lin","yue","lin"}) );
        set("title", "饿虎寨 大当家"NOR);
        set("nickname", HIB"岳老大"NOR);
        set("gender", "男性");
        set("age", 43);
	set("long",
"岳老大的身材并不高大，肩却极宽，腰是扁的，四肢长而有力，只要
一伸手，就可以看见一块块肌肉在衣服里跳动不停。他的脸上却很少
有什么表情，古铜色的皮肤，浓眉狮鼻，却长着双三角眼，眼睛里精
光四射，凛凛有威，看起来象是条随时随地都准备扑起来择人而噬的
高山豹子。这个人看来不但彪悍勇猛，而且还一定是天生的神力。\n"
	);

        set("combat_exp", 200000+random(20)*10000);
        set("score", 170);
	set("attitude","friendly");

        set("bellicosity", 600);
              
        set_skill("force", 60);
        set_skill("blade", 100);
	set_skill("wind-blade",100);
	set_skill("parry", 80+random(50));
        set_skill("dodge", 70+random(50));
	
	map_skill("blade", "wind-blade");
	map_skill("parry","wind-blade");
        
        setup();

        carry_object(__DIR__"obj/heavy_blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        
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
		command("say 你小子哪儿来的？他奶奶的，老子谁都敢砍！");
		this_object()->kill_ob(me);
	}
	else
	{
		command("say 老山东，下回岗下要是有什么油水可捞，可要迅速通报......\n对了，烧鸡带了多少？");
	}
}

