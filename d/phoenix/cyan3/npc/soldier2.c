#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
        set_name("明霞守备长", ({ "fengyun garrison", "garrison" }) );
        set("long","
这是个正在执行守城任务的值勤兵，虽然和许多武林人物比起来，这些小兵
的武功实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [32m\n");
        set("attitude", "heroism");
	set("no_heal",1);


	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"明霞守备长道：一寸山河一寸血，兄弟今天可是打算把命留在这儿了！\n"NOR,
		CYN"明霞守备长道：兄弟们千万守住，咱这道关一开，那些鬼子可就能长驱直入，血洗中原了！\n"NOR,
	}) );

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}


