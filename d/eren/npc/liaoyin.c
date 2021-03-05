#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;
int kill_him();

void create()
{
	set_name("了因师太",({"liaoyin"}));
    	set("title",YEL"梅花庵主持"NOR);
	set("long", "
一个青衣白袜的老尼，双手合什，正站在大殿前的石阶上看着你。她的人干
瘪得像是落叶一样，苍老枯黄的脸上，刻满了寂寞悲痛的痕迹，人类所有的
欢乐，全已距离她太远，也太久了。可是她的眼睛里，却还是带着一丝希冀
之色。\n");
	set("gender","女性");
	set("age",59);
	set("combat_exp", 5500000);
        set("attitude", "friendly");
	
	set("inquiry", ([
//             "白天羽" : (: kill_him :),
//             "桃花娘子" : (: kill_him :),
      	]));
	
	set("reward_npc",1);
	set("difficulty",5);
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(70) :),    
        }) );
	
	
	auto_npc_setup("liaoyin",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/necklace",([	"name": "檀木佛珠",
    						"long": "一条檀木佛珠连成的颈链。\n",
    						"value": 1,
    						 ]))->wear();    
}


int kill_him()
{
        object me, another;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"了因师太现在没空回答你。\n");
 		return 1;
 		}
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“我等了十九年，我就知道一定还会有人再来的，现在
我果然等到了。”\n"NOR,this_object());
        another = new(__DIR__"taohua");
	another->move(environment(this_object()));
        destruct(this_object());
        return 1;
}