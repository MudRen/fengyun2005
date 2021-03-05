inherit NPC;
#include <ansi.h>

void create()
{
        set_name("云铮", ({ "yun zheng" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"一个面如冠玉、满身白衣的少年。\n"
);
        set("inquiry", ([
        ]) );
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"云铮放声狂笑道：“大旗门英才辈出，我今日即便死了，一样有人来寻你复仇!\n",
	}) );
	  
        set("attitude", "friendly");
        set("title",HIW"大旗子弟"NOR);
        set("score", 10000);
        set("class", "tieflag");
        set("reward_npc", 1);
	set("difficulty", 1);

        
        set("combat_exp", 2000000);        

	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.chansi" :),
        }) );

          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("hanmei-force", 150);
	set_skill("tie-steps",100);
	set_skill("ill-quan",100);
        
        map_skill("unarmed","ill-quan");
        map_skill("force", "hanmei-force");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");
        
        set_temp("apply/armor", 30);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

 
