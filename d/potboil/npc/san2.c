// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("马离山", ({ "ma lishan","ma","lishan" }) );

		set("class","assassin");
		set("title",CYN"间关三神山"NOR);
		set("nickname",MAG"望山"NOR);

		set("always_duxin",1);

        set("gender", "男性" );

		set("age",47);

		set("chat_chance",1);
		set("chat_msg", ({
			"马离山嘀咕道：花紫藤和王正中那两个家伙原来竟是魔教手下……\n",
		}) );

        set("combat_exp", 7100000);

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(25) :),
       	}) );
        
        set("perform_weapon_attack",	"berserker/spear/eclipse-spear/riyuetongtian");
		set("skill_type_w", 			"spear/eclipse-spear");

        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 200);
        set_skill("unarmed", 200);
        set_skill("spicyclaw", 350);
        set_skill("spear", 200);
        set_skill("eclipse-spear", 200);

        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "lefthand-sword");
        map_skill("spear", "eclipse-spear");
        map_skill("parry", "eclipse-spear");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("望时枪", ({ "spear" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("间关赤袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
