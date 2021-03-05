// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("石重", ({ "shi chong","shi","chong" }) );

		set("class","assassin");
		set("title",BLU"千斤顶"NOR);
        set("gender", "男性" );

		set("age",47);
		set("chat_chance",1);
		set("chat_msg", ({
			"石重嘀咕道：魔教没事发召集令找俺干啥？\n",
		}) );

        set("combat_exp", 5100000);

		set("perform_weapon_attack", "assassin/hammer/longfenghuan/longfengshuangfei");
	
		set("chat_chance_combat",100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);
        set_skill("unarmed", 200);
        set_skill("hammer", 200);
        set_skill("longfenghuan", 186);
        set_skill("lingxi-zhi", 140);
		set_skill("force",200);
		set_skill("jingxing",200);
		set_skill("perception",200);
		
        map_skill("force", "jingxing");
        map_skill("hammer", "longfenghuan");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "lefthand-sword");
        map_skill("parry", "longfenghuan");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("千斤铜鼎", ({ "ding" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("油皱皱的布衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

