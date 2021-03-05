#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("孙巨",({"sun ju","sun","sunju"}));
	set("long","
一颗巴斗般大的头颅，顶上光秃秃的，连一根头发都没有，一张脸白里透青，
青里发白，活像是戴着个青铜面具。但却绝不是面具，因为他的鼻子在动，正
在长长地吸着气。看他吸气的样子，就像是已有很久都没有呼吸过了，这难道
不是人，难道是个刚从地狱中逃出来的恶鬼。\n");
   	
     	set("gender","男性");
     	set("title","巨人");
    	set("age",52); 	 	
    	
    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
    	set_skill("lingxi-zhi",200);
    	set_skill("iron-cloth",200);
    	set_skill("jin-gang",200);
    	set_skill("unarmed",250);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	set_skill("five-steps",200);
    	
    	map_skill("unarmed","lingxi-zhi");
    	map_skill("iron-cloth","jin-gang");
    	map_skill("dodge","five-steps");
    	
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

