// jiayi.c

inherit NPC;

void create()
{
    	set_name("无名夫人",({"old woman","woman"}));
    	set("long","她当年定是天香国色，可是现在...\n");
    	set("gender","女性");
    	set("age",42);
    
    	set("no_arrest",1);
    	set("combat_exp",2000);  
    	
    	set("int",22);
    
    	set("gin",1000);
    	set("max_gin",1000);
    	set("eff_gin",1000);
    	set("max_sen",1000);
    	set("sen",1000);     
    	set("eff_sen",1000);
    	set("force",100000);
    	set("max_force",100000);
    	
    	set("attitude", "friendly");
		set("inquiry",	([
			"嫁衣神功":	"武道禅宗，嫁衣神功，九死一生，终成正果。\n",
			"明玉功":	"。。。。，明玉神功，。。。。，天下无敌。\n",
		]));		
			
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();   
    	carry_object(__DIR__"obj/jiabook");  
}
