#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("无知小儿", ({ "kid" }) );
	set("no_attack",1);
	set("value",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N大哭道：妈妈爸爸，有坏人叔叔打我！\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N大叫道：雷公雷公，快来劈死这个坏人！\n\n"HIW"只听得惊雷乍响，一道雪亮的闪电从天而降，劈在你身边半尺之旁！\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N摇头道：杀我们不合算的哩，我们两个人才算一个人的哩！\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,6);
	message_vision("$N们前推后拥地冲了过来。\n",this_object());

}