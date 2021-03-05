inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("老老妇人", ({ "old woman" }) );
        set("nickname",HIR "帝王谷" NOR);
        set("gender", "女性");
        set("age", 85);
        set("long","“帝王谷主“的元配夫人，她面容虽然枯瘦苍老，但双目却锐如鹰隼，顾盼
之间，散发着一种威鸷而深沉的光彩，令人心惊。\n");

      
      	set("chat_chance", 1);
		set("chat_msg", ({
	 		"老妇人用凌厉的眼光看着你，你只觉得不寒而栗。\n",
		}) );
	  
        set("attitude", "friendly");
        set("score", random(20000));
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 5);
        set("combat_exp", 4800000);        
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","tanzhi-shentong2",1);
        setup();

        carry_object(__DIR__"obj/b_stone")->wield();
		carry_object(__DIR__"obj/b_skirt")->wear();
		if (!random(10)) carry_object(BOOKS"throwing_75");
}