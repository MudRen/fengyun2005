#include <ansi.h>
#include <combat.h>

inherit NPC;

void do_fight();
object offensive_target(object me);
void create()
{
	set_name("公孙大娘", ({ "gongsun daniang" }) );
	set("gender", "女性" );
	set("title", "七彩霓裳  红鞋子");
	set("nickname",HIW"剑器动四方"NOR);
    set("age", 58);
	set("int", 65);
	set("per", 5);
	set("str", 50);
	set("fle", 50);
	set("dur", 42);
	set("cor", 60);
	set("agi",80);
    set("long",
"一个灿烂如朝霞，高贵如皇后，绰约如仙女殷的美丽女人。\n
甚至连她身上穿的衣服都不是人间所有的，而是天上的七彩霓裳。\n
她盈盈走过来，身上的七彩霓裳无风自动  就像是有千万条彩带飞舞。\n");
        set("force_factor", 120);
        set("max_force",9000);
	set("force",9000);

        set("combat_exp", 10000000);
        set("score", -90000);
        set_skill("unarmed", 220);
        set_skill("throwing", 200);
        set_skill("force", 300);
        set_skill("parry", 450);
        set_skill("literate", 110);
	set_skill("dodge", 350);
	set_skill("demon-force", 250);
	set_skill("demon-strike",300);
	set_skill("demon-steps",200);
	
		
	map_skill("force", "demon-force");
	map_skill("unarmed","demon-strike");
	map_skill("dodge","demon-steps");
	map_skill("move","demon-steps");
	map_skill("throwing","tanzhi-shentong");
	set("chat_chance",1);
	set("chat_msg",({
		"公孙大娘冷冷道：“可是这一剑若是由他使出来  就末必能胜得了我。”\n",
		"公孙大娘道：“喝酒要穿喝酒的衣服， 比剑也得穿比剑的衣服！\n因为衣服也可以影响人的心情，也因为女人天生就喜欢换衣服。”\n",
		})	
	);
      
	setup();
/*	carry_object(__DIR__"obj/grey_cloth")->wear();
	carry_object(__DIR__"obj/owl_shoes")->wear();
	carry_object(__DIR__"obj/fried_nuts")->wield();
  */      
}

/*
void heart_beat()
{
	::heart_beat();
	if(is_fighting())
		smart_fight();
}

smart_fight() {
	
}
*/


	