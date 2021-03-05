inherit NPC;
#include <ansi.h>

void create()
{
    set_name("胡老五", ({ "hu laowu", "hu","laowu" }) );
	set("gender", "男性" );
        set("nickname", HIB "跛子"NOR);
	set("age", 50);
	set("per", 30);
	set("class","wolfmount");
	set("attitude","friendly");
	set("long",
		"双肩一高一低，双足一长一短。看上去是不堪一击。但是他有一双炯\n炯有神的眼睛，透着机敏，果断，谦和，和坚毅的神情。\n"
		);
	
	set("cor",200);
	set("combat_exp", 2000000);
	set("score", 1000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
   set_skill("xinyue-dagger", 111);
	set_skill("parry", 150);
	set_skill("dodge", 100);
	set_skill("dagger", 100);
	set_skill("dragonstrike",150);
	set_skill("xueyeqianzong",160);
        
      	
	map_skill("unarmed","dragonstrike");
	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","xueyeqianzong");
	map_skill("parry","xinyue-dagger");
	
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
     		(: perform_action, "dagger.douzhuanxingyi" :),
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
}
