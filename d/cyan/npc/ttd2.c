// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("久歌", ({ "jiu ge","jiu","ge" }) );
        set("title","明霞山 侍童"NOR);
		set("nickname",WHT"拂长剑，寄白云，一生一爱一瓢饮"NOR);
        set("gender", "男性" );
		set("class","berserker");

		set("group","couple");

		set("age",21);


        set("combat_exp", 5050000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform knockdown") :),
             }) );


        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("tempestsword", 200);
        set_skill("13-sword", 150);

        map_skill("sword", "tempestsword");
        map_skill("parry", "tempestsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("梅花短剑", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(CYN"涤青长衣"NOR, ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
