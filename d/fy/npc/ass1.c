// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("青衣病夫", ({ "qingyi ren","ren" }) );
        set("gender", "男性" );
		set("class","assassian");

		set("age",25);
		set("annie/duxin",1);

        set("long","这人蜡黄的面色在昏灯下看来仿佛得病已久，\n应该躺在床上吃药，却在这里吃面。\n");

        set("combat_exp", 600000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: ccommand("perform duxin") :),
             }) );
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);

        map_skill("sword", "lefthand-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("二尺剑", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("打湿的青衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}
