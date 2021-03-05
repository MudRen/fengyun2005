#include <ansi.h>

inherit NPC;
void create()
{
        set_name("司马小烟", ({ "sima"}) );
        set_temp("condition_type",RED"< 奄奄一息 >"NOR);
        set("gender", "男性");
        set("age", 12);
        set("long",	"
一个十二三岁的小孩，眼中露出和其年龄不相符合的成熟。
他被反绑在柱子上，你可以解救他。(Loose)
他的胸口插了一把尖刀，已经奄奄一息了。\n"
	);
		set("inquiry",	([
			"*":	"action小烟气息奄奄，说不出什么话来了。\n",
			]));
		
		set("combat_exp",3000);
		set("loose",0);
        set("NO_KILL","这么可怜的小孩儿，怎么舍得杀？\n");
        setup();
		carry_object("/obj/armor/cloth")->wear();
}


		