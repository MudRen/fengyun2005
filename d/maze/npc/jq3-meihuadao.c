#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("梅花盗",({"meihuadao","dao"}));
	set("title",MAG"半裸的"NOR);
   	set("long","被赤虚抱在怀里的半裸的她，一张藏在粉色柔纱后的脸隐隐现出得意之色。\n");
     	set("gender","女性");
     	set("age",20);
    	
    	set("attitude","friendly");
    	set("class","huashan");
    	set("combat_exp",400000);  
    	    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	set_skill("perception",200);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
	set("NO_KILL","梅花盗悬浮在半空之中，你根本无法碰到他 ！\n");
	set_temp("condition_type",WHT "<半空中>" NOR);
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
}
