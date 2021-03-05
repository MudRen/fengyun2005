// chuenyu.c
inherit NPC;

void create()
{
        set_name("刘老农", ({ "old liu", "liu" }) );
        set("gender", "男性" );
        set("age", 57);
        set("no_arrest",1);
        set("per", 10);
        set("long", @LONG
刘老农今年快六十了。但手脚还算灵活，在黑松山脚下种着一亩六分薄地，
与唯一的孙女儿小娟相依为命。
LONG
);
        set("attitude", "peaceful");
        set("combat_exp", 10000);
        
        set("marks/老刘本人", 1);
        
        set_skill("sword", 150);
        set_skill("unarmed", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("bai-quan", 70);
        set_skill("doomsword",150);
        set_skill("chaos-steps", 120);
        map_skill("unarmed","bai-quan");
        map_skill("dodge", "chaos-steps");
        map_skill("sword","doomsword");
        
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
	
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",8 , ob);
        }
}


void greeting(object ob)
{
        object book, juan;
        object sword;
		int bonus;
        if (!ob || environment(ob)!=environment(this_object()))	return;
        	
        if(ob->query_temp("marks/xiaojuan_murder") == 0)
        {
        	if( !ob->query("marks/老刘")) 
        		say( "刘老农说道：“这位"+ RANK_D->query_respect(ob) +"，可否见到小女娟儿？” \n");
        	else   	
        	{
        		juan = present("xiao juan",environment(this_object()));
        		if (!juan || juan->query("id")!= "xiao juan") return;
        		say( "刘老农说道：“这位"+ RANK_D->query_respect(ob) +"，多谢答救小女娟儿。” \n");
        		say( "刘老农说道：“这口剑，这本密笈赠于"+ RANK_D->query_respect(ob) +"。” \n");
        		say( "刘老农说道：“此处非久留之地，我等去也。” \n");
        		say( "刘老农领着娟儿匆匆离去。” \n");
		        destruct(juan);
				ob->set("marks/老刘", 0);
	    	  	REWARD_D->riddle_done(ob,"黑松救美",10,1);
	        	if (QUESTS_D->verify_quest(ob,"黑松救美"))
					QUESTS_D->special_reward(ob,"黑松救美");
        		sword = new(__DIR__"obj/hengbing");
        		book = new(BOOKS"parry_75");
        		if (!sword->move(ob))	destruct(sword);
        		if (!book->move(ob))	destruct(book); 
        		destruct(this_object());
        	}
        }
        else
                call_out("killhim",1,ob);
}

void killhim(object ob)
{
        ob->set_temp("marks/xiaojuan_murder", 0);
        ob->set("marks/老刘", 0);
        set("title", "悲愤欲绝");
        say("刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！\n");  
        
        set("chat_msg_combat", ({
			"刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！",      
        }) );
        
        set("chat_chance", 15);
        set("chat_msg", ({
		"刘老农悲愤欲绝的骂道：你．．你．．你们居然杀了我女儿，纳命来！",            
        }) );
           
        carry_object(__DIR__"obj/hengbing")->wield();
        kill_ob(ob);
        ob->kill_ob(this_object());
}
 
