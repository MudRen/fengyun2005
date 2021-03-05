inherit SMART_NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
        set_name("王震湘", ({ "wang zhenxiang","wang" }) );
        set("gender", "男性");
        set("age", 55);
        set("long","太湖二十四舵的总舵把子王震湘王老爷子。\n");
        set("inquiry", ([
            	"俞独鹤" : (: kill_him :),
             	"俞放鹤" : (: fanghe :),
              	"俞佩玉" : (: peiyu :),
   	]));
      	 	   	
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"王震湘笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
	 	"王震湘道：好地方呀好地方！\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","太湖王");
        set("nickname", HIG"水上大豪"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",5);
	
		set("class","yinshi");
                       
        set("combat_exp", 4000000);        
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	
    	    	
    	auto_npc_setup("wang",180,175,0,"/obj/weapon/","fighter_w","thunderwhip",1);
		setup();
    	
		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/w_whip")->wield();
		if (!random(10)) carry_object(BOOKS"whip_75");
}

 
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

int fanghe()
{
    command( "say 放鹤兄是我先天无极门的掌门人。");	
    return 1;
}


int peiyu()
{
    command ("say 这小子是我义兄不成材的儿子。");
    return 1;
}
