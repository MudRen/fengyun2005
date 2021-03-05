// boater.c

inherit NPC;

void create()
{
    	set_name("老婆子",({"old boater","boater"}));
    	set("long","
她面容被岁月侵蚀，风雨吹打，划出了千百条皱纹，显得那么衰老
但一双眼睛，却仍亮如闪电，似是只要一眼瞧过去，任何人的秘密，
却再也休想瞒过她。\n");
    
    	set("gender","女性");
    	set("age",62);
    	set("no_arrest",1);
    	set("combat_exp",111110);  
      	set("NO_KILL","杀了她会阻碍交通的。\n");
    	set("attitude", "friendly");
		set("chat_chance",2);
		set("chat_msg",({
			"老婆子咿呀咿呀摇着橹。\n",
    	}) );
    	setup();
    	carry_object("/obj/armor/cloth")->wear(); 
    	carry_object(__DIR__"obj/changgao")->wield();
    	
}

void unconcious()
{
::die();
}
