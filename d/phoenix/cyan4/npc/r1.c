#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("醉醺醺的宾客", ({ "drunk guest","guest","drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N说道：酒．．．给我酒．．．\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N摇晃着脑袋道：为什么．．．你们要晃来晃去？都别动．．．\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N道：为什么杀我，我爱你啊．．．\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,1);
	message_vision("醉醺醺的宾客东倒西歪地走了过来。\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIR"\n醉醺醺的宾客打了个酒嗝，瞪眼道：我．．．我还能喝！嗝．．．\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIR"\n醉醺醺的宾客拍着一棵参天大树，口齿不清地笑道：老．．老马，你喝多了，连路都不会走了。\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIR"\n醉醺醺的宾客两眼发直，跌跌撞撞地向前奔去。\n\n"NOR,this_object());
		break;
	}
}