// laoni.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("青衣老尼" , ({ "laoni" }) );
	set("long", "
一个瘦削苍老的青衣尼，垂眉敛目，盘膝坐在神案前的蒲团上，虽然是坐着，
犹可看出身材很高大。她的眼睛几乎全是灰色的，就彷佛死水中的寒冰，而
她的脸就像是一湖死水，冷酷中又带着出奇的宁静。。");
	
	set("attitude", "friendly");
	set("class","shenshui");
   	set("age", 65);
        set("gender", "女性" );
	set("combat_exp", 6600000);
	set("per", 2);
	
	set_temp("apply/parry", 100);
	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/amount",250);
	set_temp("damage_shield/msg",MAG"$n似乎沾上了$N周围的毒雾，手脚开始不灵便起来。\n"NOR);
    	
    	set("reward_npc", 1);
	set("difficulty", 25);	
		
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
	setup();
	carry_object(__DIR__"obj/cyan_cloth")->wear();
}
