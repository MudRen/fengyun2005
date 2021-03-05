#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("王大路",({"fishman dalu","fishman","wang"}));
    	set("title","一网打尽");
    	set("long","塞外打鱼为生，似乎不可思议，王大路的本事，就是能从附近的沼泽地里捞上鱼来。\n");
    	set("gender","男性");
    	set("age",42);
    	 	
    	set("combat_exp",2500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
        	"龙鲤鱼" :	"什么龙鲤鱼，没听说过。\n",
             	"神仙鱼" :	"神仙鱼啊，嘿嘿，就我知道怎么钓，得有特定的鱼竿和鱼饵。\n",
             	"鱼饵" :	"鱼饵得用红蚯蚓，不过，我怎么会告诉你红蚯蚓在哪里呢？这不坏了我的生意么？\n",
             	"鱼竿" :	"嗯，得用我的这个鱼竿才成，一两黄金，我说不定就割爱一把。\n",
             	"bait" :	"鱼饵得用红蚯蚓，不过，我怎么会告诉你红蚯蚓在哪里呢？这不坏了我的生意么？\n",
             	"fishpole" :	"嗯，得用我的这个鱼竿才成，一两黄金，我说不定就割爱一把。\n",
             	"王小路" :	"小路是我的双胞胎弟弟，也是个渔夫，不过他那两下子比我差远了。\n",    
   	]));
    	
    	set("death_msg",CYN"\n$N叹口气说：我真想再能去钓一次鱼。。 \n"NOR);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n王大路叫道：来人啊，杀人啦！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"王大路得意洋洋地说：这儿就我能从沼泽地钓上鱼来。\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","fumostaff",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/staff")->wield();  
    
}


int accept_object(object who, object ob)
{
	object fishpole;
	
	if (ob->value()>=10000) {
		command("grin "+who->get_id());
		command("say 好吧，我就割爱一把");
		fishpole=new(__DIR__"obj/staff");
		message_vision("$N打开一个装满了鱼竿的大箱子，随便拿了一把扔给你。\n",this_object());
		if (fishpole)
		{
			if (!fishpole->move(who))
				fishpole->move(environment(who));
		}		
		return 1;		
	}
	return 0;
}	