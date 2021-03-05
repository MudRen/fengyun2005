inherit NPC;
#include <ansi.h>

void create()
{
        set_name("蓑笠老翁", ({ "old man", "man"}) );
        set("title", HIB"沧海一粟"NOR);
		set("gender", "男性" );
		set("age", 244);
		set("per", 65);
		set("int",28);
		set("attitude","friendly");
		
		set("max_force", 1000);
		set("force", 1000);
		set("force_factor",50);

		set("long",HIW"
一个蓑衣斗笠的白胡子老者，脸色红润，颏下银髯，童颜鹤发，当真便如图
画中的神仙人物一般。正自盘膝闭目而坐，垂钓怒礁。\n"NOR
	);
		set("inquiry",([
			"*":	"action蓑笠老翁闭目而坐，不发一语。\n",
		]));
	
		set("chat_chance", 1);
		set("chat_msg", ({
	        name()+"如石雕般在海风巨浪中纹丝不动，安然垂钓。\n",
	        }) );
		
	    set("combat_exp", 40000000);
		
		set_skill("move", 200);
		set_skill("dodge", 200);
		set_skill("force", 160);
		set_skill("unarmed",200);
	    set_skill("changquan",200);
		set_skill("parry",200);
		
	    map_skill("unarmed", "changquan");
		
		set("NO_KILL","你似乎遇到了一堵气墙，竟是无法前进半分。\n");
		setup();
        carry_object(__DIR__"obj/douli")->wear();
        carry_object(__DIR__"obj/suoyi")->wear();
}

void init()
{       
	object ob;
	::init();
	if ( interactive(ob = this_player()) && !is_fighting() ) 
   {
	 remove_call_out("greeting");
	 call_out("greeting", 1, ob);
   }
}

void greeting(object ob)
{
	object reward;
	if (!ob || environment(ob)!= environment()) return;
		
	if (REWARD_D->riddle_check(ob,"王图一梦") ==13)
	{	
		if (ob->query_temp("is_unconcious")){
			ob->revive();
			tell_object(ob,"你缓缓醒了过来。\n眼前是张慈祥的满是皱纹的老人的脸，关切的看着你。\n");
		}
		message_vision(CYN"
蓑笠老翁长笑一声，慈声道：好孩子，天下苍生，因你得避此劫，实可自傲。

蓑笠老翁面向怒海，长叹一声，悲道：孤城啊孤城，王图霸业，转眼成空，
你为何至死都看不破呢？兴也苦，亡也苦，成也空，败也空。\n "NOR, ob);


		message_vision(WHT"
蓑笠老翁长袖一拂，竟然临空踏海而去！

海天苍茫，狂风怒浪中老翁终于消失不见。。\n\n"NOR, ob);
		REWARD_D->riddle_set(ob,"王图一梦",14);
//		destruct(this_object());		so 2nd one entering won't get confused 
	}
}

