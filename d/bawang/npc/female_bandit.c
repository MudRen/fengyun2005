#include <ansi.h>
inherit NPC;

void create()
{
    set_name("女土匪", ({ "female tufei" }) );
    set("nickname", HIM "绿林巾帼 不让须眉"NOR);
    set("title",  "饿虎寨 压寨夫人"NOR);
	set("gender", "女性");
    set("per", 5);
	set("age", 19);
	set("long",     
		"恶虎岗自然也有女人，多是不爱红装爱刀枪。她们大都个个青春年少，\n身材健美。她们正在进行日光浴，一边朝你抛媚眼儿。\n");
	set("combat_exp", 11000);
	set("score", 100);
	set("attitude", "friendly");
	set_skill("unarmed", 75);
	set_skill("tenderzhi",60);
	set_skill("parry", 15);
	set_skill("dodge", 50);
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/doudu")->wear();
}
