#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        string *name = ({"菩注","除忧","大忍","无忧自在","妙惧","严土","金髻","雷德",
"雷音","香象","马头","明首","敬首","众首","金髻","辨德",
"羼提","悟达","法灯","离垢","境界","马胜","天王","无胜",
"自净","不动","调达","普光","普光","智积","宝幢","善慧",});
        set_name(name[random(sizeof(name))]+"尊者", ({"shaolin monk","monk"}) );

    	set("title","少林寺 铁罗汉");
    	set("long", "少林一百零八罗汉之一。\n");

	set("age",40);
	set("combat_exp", 4500000);
	set("class","shaolin");        	
	if (!random(5))	set("attitude","aggressive");
	set("target_name","铁罗汉");
	
	set("maze","shaolin");
		
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		(: auto_smart_fight(20) :),
        }) ); 		

	switch (random(8)) {
		case 0:	auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","lianxin-blade",1); 	break;
		case 1: auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","liuxing-hammer",1);	break;
		case 2: auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","wuche-axe",1);	break;
		case 3: auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","fumostaff",1);	break;
		case 4: auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","tianlongwhip",1); 	break;
		case 5: auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","xingyi-stick",1);	break;
		case 6: auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","yijinjing",1);	break;
		default: auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","shangren",1);
	}
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "少林罗汉服",
    						"long": "少林罗汉的僧衣。\n",
    						 ]))->wear();  

}

