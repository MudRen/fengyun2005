inherit NPC;
#include <ansi.h>
void  smart_fight(object who);

void create()
{
        set_name("邱独", ({ "qiu du" }) );
        set("title",HIB "魔手追魂" NOR);
        set("gender", "男性");
        set("age", 26);
        set("long",
"他一袭黑衣，身形异常高大，手上戴着双暗青色的铁手套，形状
看来丑恶而笨拙，颜色令人一看就不禁毛骨悚然。\n"
);
        set("attitude", "friendly");
        set("combat_exp", 700000);
        set("score", 2000);

        set("class", "assassin");

      	set("pursuer", 1);

	set_skill("flame-strike",130);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("devil-spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("gouyee", 100);
	set_skill("jinhong-steps",160);

        map_skill("spells", "devil-spells");
        map_skill("force", "gouyee");
        map_skill("axe","xuanyuan-axe");
        map_skill("dodge","jinhong-steps");
        map_skill("parry","xuanyuan-axe");
        map_skill("move","notracesnow");
        map_skill("unarmed","flame-strike");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

	set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	(: smart_fight(this_object()) :),     
        }) );

	carry_object(__DIR__"obj/devil_hand")->wield();
	carry_object(__DIR__"obj/devil_hand")->wield();
	carry_object(__DIR__"obj/black_cloth")->wear();
}

void smart_fight(object who)
{
	int i;
	object *enemy;
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
		if (!enemy[i]->query_temp("till_death/lockup"))
			who->perform_action("dodge.canglongzhaxian");
	}
	}
	
}



int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

void die()
{
//      object book;
        object me, owner/*,*team,*team2*/;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
			me = owner;
		} 
		
        if (me)	
       		me->set("marks/邱独",1);
                
        ::die();
}
	