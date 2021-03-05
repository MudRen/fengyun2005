// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("蓝天猛", ({ "lan tianmeng","lan","tianmeng" }) );

		set("class","assassin");
		set("title",YEL"狮王"NOR);
//		set("nickname",BLU"分光捉影　一手七杀"NOR);

        set("gender", "男性" );
		set("age",47);

		set("chat_chance",1);
		set("chat_msg", ({
			"蓝天猛恭恭敬敬地道：以后也绝不会再有人等莫之许他们。\n",
		}) );
		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

        set("combat_exp", 5100000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("九十三斤撼天椎", ({ "hammer" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("狮王铁衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
