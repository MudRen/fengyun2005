// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("很规矩的年轻人", ({ "young man","man" }) );
        set("gender", "男性" );
		set("class","assassian");

		set("age",15);
		set("annie/duxin",1);

        set("long","一个看起来规规矩矩的年轻人。\n");

        set("combat_exp", 800000);


        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: ccommand("perform sharenruma") :),
             }) );
        set_skill("sword", 100);
        set_skill("sharen-sword", 100);
        map_skill("sword", "sharen-sword");


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("短锈剑", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("规规矩矩的布衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}
