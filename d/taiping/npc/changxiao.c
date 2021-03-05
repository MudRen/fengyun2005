#include <ansi.h>
#include <command.h>

inherit SMART_NPC;
int letter();

void create()
{

		set_name("常笑",({"chang xiao","chang","xiao"}));
    	set("nickname","毒剑");
    	set("title",WHT"四大名捕"NOR);
    	set("long", "
他面上挂着笑容，和蔼的笑容，相貌亦是一副慈祥的相貌，即使穿上了官服，他也
是显得和蔼可亲。有谁想到这样的一个人，他的心，他的剑，竟比毒蛇还狠毒？他
今年不过三十六岁，做这份工作不过十年，死在他手上的人却已过千。平均每三日，
就有一个人死在他手上。知道这些事的人，是不是仍觉得他和蔼可亲？\n");
		set("age",47);
		set("combat_exp", 9000000);
        	
		set("reward_npc",10);
		set("ssrm_7hit",1);  
		
		set("inquiry", ([
        	"tie hen" : 	"铁手无情，嘿嘿，我倒要看看他究竟是个什么角色。\n",
           	"铁恨" : 		"铁手无情，嘿嘿，我倒要看看他究竟是个什么角色。\n",
   			"珠宝": 	(: letter :),
   			"太平王府":	(: letter :),
   			"死人":			"我十三个手下中的林二是仵作高手，没有他查不出来的死因。\n",
   			"毒":			"我十三个手下中的唐大是用药高手，没有他认不出来的毒药。\n",
   		]));
    	
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"常笑冷笑道：这太平王府珠宝一案，非查个水落石出不可。\n",
    	}) );  
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n常笑冷冷道：这儿某个人的咽喉之上立即会多出一个血洞了！\n",
        ]) ); 
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
    	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	
		setup();
		carry_object(__DIR__"obj/o_cloth2")->wear();
		carry_object(__DIR__"obj/o_sword")->wield();
}


int letter(){
	
	command("heihei");
	command("say 太平王府珠宝失窃一案，疑点甚多，什么血鹦鹉索命，真是一派胡言。");
	command("say 数月前部分珠宝在大盗满天飞手中出现，没想到，口供尚未问出，满天飞
便"YEL"毒"CYN"发身亡，而审讯他的，竟然是四大名捕中的铁恨！");
	command("say 而铁恨竟然也死了，据说又是死在血鹦鹉手中。");
	command("say 我到此地，便是要把此案查个水落石出。");
	command("say 就是"YEL"死人"CYN"，我也能叫他张口！");
	
	this_player()->set("marks/parrot/常笑",1);
	return 1;
}
	
	