#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("薛大汉",({"xue dahan","xue","dahan"}));
		set("title","绿林好汉");
   		set("long","
一条身高八尺的彪形大汉，肩膀几乎有平常人两个宽，一双蒲扇般的
大手垂下来，几乎已盖过了膝盖，脸上颧骨高耸，生着两道扫帚般的
浓眉，一张大嘴。他身上穿的衣服虽然又脏又破，但一站起，可是威
风凛凛，叫人看着害怕。\n");
     	set("gender","男性");
    	set("age",32);
    	 	
    	set("combat_exp",4300000);  
   	
    	set("reward_npc",5);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );
        
        set("death_msg","薛大汉长长地吐了口气，仿佛是悲哀、叹息，“我本来想把你当作朋友的”\n");
        
        set("inquiry", ([
        	"薛斌" : "家父退出江湖已经十多年了，要想找他，可以到大雪山
附近去打听一下薛家庄。\n",
		"xuebin" : "家父退出江湖已经十多年了，要想找他，可以到大雪山
附近去打听一下薛家庄。\n",
      	]));
            	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"薛大汉击掌唱道：“九月十五月当头，月当头兮血可流，流不尽的英雄泪，杀不尽的仇人头！”\n",
			"薛大汉拿起酒袋咕噜噜地灌下几口花雕酒，抹抹嘴大笑起来。\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","zhangjian",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/wine1");
}
