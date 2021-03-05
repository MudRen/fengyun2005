#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	string *num = ({"红","黄","蓝","绿"});
	set_name( num[random(4)]+"袍公" , ({ "oldguy" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N恨恨道：若老夫能聚．．．聚酒．．．\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N大哭道：黑袍黑袍，你独占了白袍也就罢了，为什么还要杀我．．．\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N怒目圆瞪，拼尽最后一丝力气咒你：咒你被风吹干，变成一具骸骨，见塔祝，拜孟婆！\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,2);
	message_vision("$N东倒西歪地走了过来。\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIW"\n$N满面通红，呼吸间尽是酒味。\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIW"\n$N运劲将内力凝聚，全身上下升起了一团臭味熏人的酒气．．．\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIW"\n$N自言自语道：没想到当年的小娃子现在已经长得这么大了，岁月催人老啊。\n\n"NOR,this_object());
		break;
	}
}