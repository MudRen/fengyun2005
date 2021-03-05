#include <ansi.h>
inherit SMART_NPC;

int do_running();

void create()
{
    	set_name("马小宝",({"ma xiaobao","xiaobao"}));
	set("long","
小宝和小贝是马方中的一双心肝宝贝，无论他们要什么几乎全都有求必应，
就算做错事，马方中也没有责备过他们一句。只要一空下来，就会陪他们到
处去玩。\n");
   	
     	set("gender","女性");
     	set("group","ma");
     	
    	set("age",10); 	 	
    	    	
    	
    	set("combat_exp",50000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	"有事儿去问我爸我妈吧。\n",
   		]));
        
        set("arrive_msg","跳跳蹦蹦地跑了过来");
    	set("chat_chance",20);
    	set("chat_msg",({
				(: do_running :),
    	}) );    	    	
    	
		
		setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

int do_running(){
	
	object room1,room2,env;
	
	if (query_busy())	return 1;
		
	env = environment();
	if (env->query("ma_room1")){
		set("leave_msg","跳跳蹦蹦地从里屋奔到外屋");
		ccommand("go north");
		return 1;
	}
	
	set("leave_msg","跳跳蹦蹦地又从外屋冲进里屋");
	ccommand("go south");
	return 1;
		
}
