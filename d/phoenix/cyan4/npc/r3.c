#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("不动和尚", ({ "drunk monk","monk","drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N一拍脑门：对啊，人死了不就不动了，我怎么没想到！\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N道：小僧．．小僧再也不破戒了．．\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N对你挥手道：我死先，你马上过来。\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,3);
	message_vision("$N东倒西歪地走了过来。\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIG"\n$N问你道：时有风吹幡动，是风动，是幡动？\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIG"\n$N双手合十：这位施主，可否施舍小僧一些酒钱？\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIG"\n$N舔舔嘴唇，笑道：这老儿珍藏的百年泥香还真是不错。\n\n"NOR,this_object());
		break;
	}
}