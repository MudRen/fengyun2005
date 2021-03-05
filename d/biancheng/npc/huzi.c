#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("小虎子",({"xiao huzi","huzi"}));
   	set("long","
孩子满身红衣，头上一根冲天杵小辫子，也用条红绸带系住，身子长得虽然
特别瘦小，但眼睛却特别大，一双乌溜溜的眼珠子，不停地转来转去，显得
又活泼、又机灵。。\n");
     	
     	set("gender","男性");
    	set("age",12);
		set("group","guo");
		
		set("max_kee",3000);
		set("max_sen",3000);
		set("max_gin",3000);
		
    	set("combat_exp",1000000);  
    	set("attitude", "friendly");
    	
    	setup();
    	carry_object("/obj/armor/cloth",([	"name": RED"红绫袄"NOR,
					"long": "一件红绫袄。\n",
					 ]))->wear();   
    
}
