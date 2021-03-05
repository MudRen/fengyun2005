inherit SMART_NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
	object armor;
        set_name("王雨楼", ({ "wang yulou","wang" }) );
        set("gender", "男性");
        set("age", 55);
        set("long","侠名遍江湖，仁义传四海，一个浓眉长髯，面如重枣的紫袍老人。\n");
        set("inquiry", ([
            "俞独鹤" : (: kill_him :),
             "俞放鹤" : (: fanghe :),
              "俞佩玉" : (: peiyu :),
   	]));
      	 	   	
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"王雨楼笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
	 	"王雨楼道：好地方呀好地方！\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","江南大侠");
        set("nickname", HIG"义薄云天"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","beggar");
        
        set("combat_exp", 4500000);        
               
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();

	armor=new("/obj/armor/cloth");
	armor->set_name(HIY"烟雨潇潇环金袍"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
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