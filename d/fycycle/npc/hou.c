
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
	set_name("中年汉子", ({ "hou", "hou er"}) );
	set("gender", "男性" );
	set("age", 50);
	set("int", 25);
	set("per", 23);
	set("long","一个身形瘦削的中年汉子。\n");
	
	 set("inquiry", ([
                "五大掌门": 
"他们是昆仑派卓腾，点苍谢长卿，崆峒厉鹗，峨嵋苦庵和武当赤阳，不过听说主谋只是其中三人，另两人还罪不致死。\n",
        ]) );
	        
	set("toughness",300);
	set("combat_exp", 20000000);
	
	set_skill("unarmed", 300);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("move", 400);
	set_skill("dodge", 300);
	set_skill("qiuzhi-sword", 300);
	set_skill("xianjing", 250);
	set_skill("liuquan-steps", 300);
	set_skill("dragonstrike",300);

	set("resistance/kee",90);
	set("resistance/gin",90);
	set("resistance/sen",90);
	    
	map_skill("unarmed","dragonstrike");
	map_skill("sword", "qiuzhi-sword");
	map_skill("force", "xianjing");
	map_skill("dodge", "liuquan-steps");
	map_skill("move", "liuquan-steps");
	
	set("chat_chance", 1);
	set("chat_msg", ({
	
	}) );
	setup();
	carry_object("/obj/armor/cloth", 
	    		([ 	"name" : "布衣",
	    			"long" : "一件灰色长袍。\n"]) 
	    		)->wear();
	carry_object("/obj/weapon/sword")->wield(); 
}

void init(){
	object ob;
	
    	::init();
    	if( interactive(ob = this_player()) && !is_fighting() ) {
        	remove_call_out("greeting");
            	call_out("greeting", 2, ob);
    }
}

void greeting(object ob){
	message_vision("$N打量了$n一下，脸上丝毫没有任何表情。\n", this_object(), ob);
	if(ob->query("marks/梅山民")) {
	if(ob->query("m_killer/厉鹗") && ob->query("m_killer/赤阳道长")
		&& ob->query("m_killer/苦庵上人") && ob->query("marks/谢长卿"))
		tell_object(ob, "你听一个微小的声音说道：“去书房，推开花纹砖（ｐｕｓｈ　ｓｔｏｎｅ）向下，你可以学
到无敌的功夫。\n");		
	}
}	

