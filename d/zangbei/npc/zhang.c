#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("张老头",({"old zhang","zhang"}));
//    	set("title","温柔贤惠");
   	set("long","
张老头是个孤苦的老人，一生都在默默地替别人耕耘，唯一的珍宝是他的
独生女儿。每年秋收，他都会将院里最大的瓜和最甜的葡萄留下来，去送
给一个人，表示他对这人的爱和尊敬，这个人就是菊花园的老伯。\n");
   	
     	set("gender","男性");
     	     	
    	set("age",62); 	 	
    	set("int",52);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
    	set_skill("staff",200);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	
    	set("inquiry", ([
 		"独生女儿": "如果不是老伯做主，小珍早就没命了，这不，我正挑着些果子去谢老
 伯呢。\n",
 		"女儿":	     "如果不是老伯做主，小珍早就没命了，这不，我正挑着些果子去谢老
 伯呢。\n",
 		"老伯":	"老伯是我这一辈子唯一可以信赖的人。无论遇着多么大的困
难，老伯都会为我解决，无论受了多么大的委屈，老伯都替我出气，为我
主持公道。只有那些丧天良的人才会跟老伯作对。\n",
		"老伯":	"老伯是我这一辈子唯一可以信赖的人。无论遇着多么大的困
难，老伯都会为我解决，无论受了多么大的委屈，老伯都替我出气，为我
主持公道。只有那些丧天良的人才会跟老伯作对。\n",
   	]));
    	
    	set("death_msg",CYN"\n$N断断续续地说：“老伯。。会为。。我。。报仇。。的。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"张老头说：“老伯可是个好人呀！”\n",
    	}) );    	    	
    	
		
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 	carry_object("/obj/item/biandan")->wield();
 	carry_object("/obj/food_item/watermelon");
}

