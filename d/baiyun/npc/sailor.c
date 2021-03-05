#include <ansi.h>
inherit NPC;

void create()
{
	set_name("水手", ({ "sailor","shuishou" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long", "一个终年飘浮在海上的人，古铜色的皮肤，结实的肌肉。\n");
    set("combat_exp", 10000+random(10000));
	set("attitude", "heroism");
    set_skill("unarmed", 50);
    set_skill("parry", 60);
    set_skill("dodge", 70);
    set("chat_chance", 10);
    set("chat_msg", ({(:random_move :)}) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
