#include <ansi.h>
inherit NPC;

void create()
{
	set_name("卜亚男", ({ "bu yanan","bu" }) );
	set("title", HIM "酒仙"NOR);
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
卜亚男从来没醉过，多少英雄好汉都倒在她的石榴裙下．
LONG
);
	set("combat_exp", 13000);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/shi_skirt")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        return 1;
}
