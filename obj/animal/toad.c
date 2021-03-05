#include <ansi.h>
inherit NPC;


void create()
{
        set_name("癞蛤蟆", ({ "toad" }) );
        set("race", "野兽");
        set("age", 5);
        set("combat_exp",1000);
        set("long", "一只身上长满疙瘩，难看之极的癞蛤蟆。\n");
        set("verbs", ({ "bite" }) );
	set("limbs", ({
		"头部",	"颈部",	"胸部",	"后背",	"腹部",	
		"前腿",	"后腿"
	}) );     
	set("death_msg",CYN"\n癞蛤蟆白肚子朝天一阵哆嗦。。。。 \n"NOR);
	set("self_go_msg",1);
	set("arrive_msg","悉悉簌簌地跑了过来。");
	set("leave_msg","一溜烟地跑掉了。");
        set_skill("dodge", 80);
        setup();
}

			