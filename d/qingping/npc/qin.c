#include <ansi.h>

inherit NPC;
void create()
{
	set_name("琴儿" , ({ "qiner", "qin er", "girl" }) );
	set("long", "一位十二三岁的小丫头。\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "女性" );
        set("inquiry", ([
        ]) );

	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(AREA_CHUENYU"npc/obj/yellow_flower")->wear();
}
