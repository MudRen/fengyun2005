#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("梅花盗",({"meihuadao","dao"}));
	set("title",MAG"千面花妖"NOR);
   	set("long","
虽然浑身赤裸，但依旧蒙着缀满梅花的轻纱；即使如此，若是见到了如此美丽
的胴体，如此纤细的腰肢，如此修长的双腿，如此坚挺的。。。。谁还能忍心
下狠手呢？\n");
     	set("gender","女性");
    	set("class","huashan");
    	set("combat_exp",400000);  
    	set("age",22);
    	 	
    	set("cor",40);
    	set("per",40);
    	
    	set("NO_KILL","你忍心下这样的狠手？\n");   	 	
    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
    	set("inquiry", ([
   	]));
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );  	
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
}
