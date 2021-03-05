inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
	set_name("伯罗各答", ({ "bo luo"}) );
	set("gender", "男性" );
	set("title",HIY"恒河三佛"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long","天竺高僧，此次聚众到少林寺,妄图一统武林。\n");
	set("class","lama");
    set("combat_exp", 4300000);
    set("score", 900);
    set("reward_npc", 1);
	set("difficulty",5);
	set("no_busy",6);

	
	set("inquiry", 	([
		"赶回西域":	"什么赶不赶的，咱们都听大师兄的。\n",
		"大师兄":	"大师兄就是咱们恒河三佛中的盘灯孚尔。\n",		
		]));
			
		
	set("chat_chance", 1);
    set("chat_msg", ({
                "伯罗各答说：嘿嘿，其实恒河只是条小河，咱们兄弟总想若是能改成‘黄河三佛’
那可真有意思！\n",
                }) );
        
    set_skill("perception",180);
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("lingxi-zhi", 160);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("jin-gang",150);
	set_skill("move",400);
	set_skill("nodust-steps",200);
	set_skill("dodge",200);
	map_skill("dodge","nodust-steps");	
	map_skill("iron-cloth","jin-gang");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	
	setup();
    carry_object(__DIR__"obj/lamacloth1")->wear();
    carry_object(__DIR__"obj/ring3")->wear();
        
}

void win_enemy(object loser)
{
	say("伯罗各答哈哈一笑说道：好说，好说。\n");

}
