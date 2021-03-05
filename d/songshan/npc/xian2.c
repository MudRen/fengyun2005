inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
	object armor;
	set_name("平凡上人", ({ "shang ren","ren"}) );
	set("gender", "男性" );
	set("title",HIW"世外三仙"NOR);
	set("nickname",HIR"大戢岛主"NOR);
	set("age", 370+random(10));
	set("class","lama");        
	set("long",
		"一个相貌异凡的老僧 这老者红光满面，笑容可掏，白髯己纷纷变成米黄色。\n"
		);
	set("class","shaolin");
        set("combat_exp", 9600000);
        set("score", random(90000));
        set("reward_npc", 1);
	set("difficulty",5);

	set("attitude","friendly");
	
	set("no_busy",8);
	
	set("chat_chance", 1);
        set("chat_msg", ({
                "平凡上人笑口盈盈，不知得意着什么。\n",
                "平凡上人说：“想学我的工夫吗？“\n",
                }) );
        
        set_skill("perception",200);
	set_skill("iron-cloth", 200);
	set_skill("yijinjing", 200);
  	set_skill("unarmed", 300);
	set_skill("force", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("puti-steps",250);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("iron-cloth","yijinjing");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "yijinjing");
	map_skill("force", "yijinjing");
    	map_skill("dodge","puti-steps");
    	map_skill("move","puti-steps");
    	
        add_temp("apply/iron-cloth", 200);
	set_skill("dual-attack",300);
	set_temp("apply/haste",300);

	setup();
        armor=new("/obj/armor/cloth");
	armor->set_name("破旧不堪的僧衣",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}



smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie()) {
		who->cast_spell("zombie-bolt");
		return;
	}
	return;
}

