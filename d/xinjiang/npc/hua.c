inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
        set_name("衣服很华丽，修饰很整洁的中年人", ({ "middle aged man", "man" }) );
        set("gender", "男性" );
        set("age", 44);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 30);

        set("long","他好象总是一个人坐在这里，一个人在玩着骨牌，很少有人看见他做过别的事。\n");

        set("combat_exp", 2000000);
         set("score", 200);
 
 	set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	(: smart_fight() :),              
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("luoriquan",150);
        set_skill("fengyu-piaoxiang",200);
        
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (!enemy[i]->is_busy()
				&& enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
				this_object()->smart_busy();
			}
			if (enemy[i]->is_busy()) {
				this_object()->smart_attack();
			} 
		}
	}
}

smart_busy() {
	this_object()->perform_action("dodge.zonghengsihai");
	return;
}
smart_attack() {
	return;
}