inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
        set_name("林瘦鹃", ({ "lin shoujuan","lin" }) );
        set("gender", "男性");
        set("age", 55);
        set("long",
"锦衣高冠，腰悬一柄满缀碧玉的长剑，头发虽然俱已花白，但看来仍
是风神俊朗，全无老态。。。\n"
);
        set("inquiry", ([
            "俞独鹤" : (: kill_him :),
             "俞放鹤" : (: fanghe :),
              "俞佩玉" : (: peiyu :),
   	]));
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"林瘦鹃笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
	 	"林瘦鹃道：好地方呀好地方！\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","苏州大豪");
        set("nickname", HIG"菱花剑"NOR);

        set("reward_npc", 1);
	set("difficulty",5);
	set("class","swordsman");   
                
        set("combat_exp", 3500000);        
	set("class","swordsman");
   
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
	set_skill("shadowsteps",200);
	set_skill("yue-strike",200);
        set_skill("softsword",150);
        set_skill("perception",150);
        
        map_skill("unarmed","yue-strike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","shadowsteps");
        map_skill("move","shadowsteps");
        map_skill("parry","softsword");
        map_skill("sword","softsword");

        set_temp("apply/armor", 30);
        setup();

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: perform_action("sword.muyufeihong") :),
        }) );

//        add_money("gold", random(4));
        carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/pozhi1");
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