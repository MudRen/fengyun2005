#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
        set_name("明霞守备", ({ "fengyun garrison", "garrison" }) );
        set("long","
这是个正在执行守城任务的值勤兵，虽然和许多武林人物比起来，这些小兵
的武功实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [32m\n");
        set("attitude", "heroism");
	set("no_heal",1);

	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"明霞守备说道：今天就是把命葬在这里，也绝不让那些五短倭贼占去中原一步土地！\n"NOR,
	}) );

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}


