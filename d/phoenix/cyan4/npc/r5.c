#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	set_name("成群结队的醉鬼", ({ "drunk" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N互相拍着肩膀笑道：走，走，哥儿们去鬼门关再喝一杯！\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N嘀咕道：也不知孟婆汤是黄汤，是白汤？\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N打了个酒嗝道：朝饮酿，夕死可矣！\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,5);
	message_vision("$N们旋转著舞了过来。\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIG"\n$N大笑：好，好酒！\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIG"\n$N齐齐唱道：五花马来千金裘，呼儿将出换美酒！\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIG"\n$N嘶哑着声音大歌：桃花仙人种桃树，又折花枝换酒钱．．换．．．酒钱．．．．\n\n"NOR,this_object());
		break;
	}
}