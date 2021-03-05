// bandit.c
#include <ansi.h>
inherit NPC;
void create() {
        set_name("土匪", ({ "tufei", "bandit"}) );
        set("long","一个满脸伤疤加横肉的家伙。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
		set("agi", 15);
		set("pursuer",1);
		set("no_return",1);
        set("combat_exp", 3000000+random(3000000));
		set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                name()+ "喝道：今天老子要钱又要命！！\n",
                name()+ "笑道：贼娘的，去死吧！\n",
				HIR+ name()+ HIR"大喊：砍死一个够本，砍死两个赚一个！！\n"NOR,
				(: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 300);
        set_skill("axe", 300);
        set_skill("blade", 300);
        set_skill("hammer", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("move", 200);

        set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 50+random(200));
        setup();
}


void init() {
    remove_call_out("hunting");
	if(environment() && !environment()->query("no_fight")) {
        call_out("hunting",1);
	}
}


void hunting() {
	int i;
	object *ob;
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
	  	if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
	if(ob[i]->query("vendetta/authority")) continue;
	        kill_ob(ob[i]);
	        ob[i]->fight(this_object());
	}
}

void setup_bandit(string name, string armor, string weapon, string mark) {
	object armor_ob, weapon_ob;
	
	set("name", name);
	armor_ob = new(armor);
	if(objectp(armor_ob)) {
		armor_ob->move(this_object());
		armor_ob->wear();
	}
	weapon_ob = new(weapon);
	if(objectp(weapon_ob)) {
		weapon_ob->move(this_object());
		weapon_ob->wield();
	}
	set("area_mark", mark);
}
