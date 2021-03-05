// taolord.c

inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name( "玉兰溪" , ({ "yu lanxi",  "yu" }) );
    	set("gender", "女性");
    	set("title", "松谷庵 主持");
    	set("nickname", HIC"空谷幽居"NOR);
    	set("age", 46);
    	set("long", "一个小尼庵的主持．\n");
    	set("reward_npc", 1);
		set("difficulty", 5);

    	set("combat_exp", 6500000);
       	set("score", 200000);
    	set("class", "taoist");

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"玉兰溪轻轻叹了口气，似乎说不尽的忧伤。。。。”\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","necromancy",1);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "蓝布道袍",
    						"long": "一件蓝布道袍，洗得已经有些发白了。\n",
    						 ]))->wear();    
    	
}
