inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
        set_name("厉鹗", ({ "li e" }) );
        set("gender", "男性");
        set("age", 65);
        set("long",
"老者穿着极为精致的丝棉袍子，背后斜背着柄长剑，那剑身很长，背在他那
枯瘦的身躯上，几乎挂到地上了，显得甚是滑稽，然而他广额深腮，目光如鹰，
望之却又令人生畏。\n"
);
	  
        set("attitude", "aggressive");
        set("title",HIW"崆峒剑神"NOR);
        set("bellicosity",400000);
        set("score", 0);
        set("class", "fighter");
        set("reward_npc", 1);
		set("difficulty",10);
        
        set("combat_exp", 3500000);        
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

        
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("doomforce", 150);
	set_skill("doomsteps",200);
	set_skill("doomstrike",200);
        set_skill("doomsword",150);
        
        set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);
        
        map_skill("spells","kwan-yin-spells");  
        map_skill("unarmed","doomstrike");
        map_skill("force", "doomforce");
        map_skill("dodge","doomsteps");
        map_skill("move","doomsteps");
        map_skill("parry","doomsword");
        map_skill("sword","doomsword");

        setup();

//        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/armor/cloth")->wear();
}

 
void init()
{	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "厉鄂狞笑着说：你来晚了，梅山民被我杀了，现在轮到你了！\n");
}

smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie()) {
		who->cast_spell("zombie2");
		return;
	}
	who->perform_action("sword.hunranyijian"); 
	return;
}  


