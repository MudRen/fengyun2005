// zhao.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("赵刚", ({ "zhao", "zhao gang" }) );
	set("title", HIY "单掌开碑" NOR);
	set("long","
大名府单掌开碑赵刚，武功之强，已可算是江湖中的一流高手,
尤擅硬功中最强的大摔碑手。
\n" );

	set("gender", "男性" );
	set("class", "wudang");
	set("age", 42);
	set("reward_npc", 1);
	set("difficulty", 3);
	
	set("attitude", "peaceful");
	set_skill("unarmed", 300);
	set_skill("shuaibei", 200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("five-steps",200);
	set_skill("move",200);
	
 	map_skill("unarmed", "shuaibei");
 	map_skill("dodge","five-steps");
 	map_skill("move","five-steps");
	map_skill("parry", "shuaibei");
	 	
 	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
  		(: perform_action, "dodge.bazhentu" :),
  		}) ); 
 	 	 	
	set("combat_exp", 4800000);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	if (!random(10)) carry_object(BOOKS"unarmed_75");
}
