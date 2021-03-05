// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("独臂人", ({ "one-armed man","man" }) );
        set("gender", "男性" );
		set("class","swordsman");

		set("age",35);
		set("annie/duxin",1);

        set("long","这人身材虽瘦如竹竿，肩膀却宽得出奇。背后斜背著一根黑\n竹竿，把一顶破旧的竹笠低低的压在眉下，只露出左边半只\n眼睛。\n");

        set("combat_exp", 1200000);


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: ccommand("perform muyufeihong") :),
             }) );
        set_skill("sword", 200);
        set_skill("softsword", 150);
        map_skill("sword", "softsword");


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(BLK"黑竹竿"NOR, ({ "bamboo stick","stick" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("破斗笠", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();
}
