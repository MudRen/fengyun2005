#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	int i;
	i=3000+random(7000);
	set_name("天下第"+CHINESE_D->chinese_number(i), ({ "super highhand","highhand","hh" }) );
	set("no_attack",1);

	switch (random(3))
	{
	case 0:
		set("death_msg",CYN"\n$N惊恐地瞪圆双目：这怎么可能！能杀老夫$N，莫非你就是传说中的天下第"+CHINESE_D->chinese_number(i-1)+"？\n"NOR);
		break;
	case 1:
		set("death_msg",CYN"\n$N咬牙道：可．．可恨，老．．老夫的．．天下第一比武大会．．．．\n"NOR);
		break;
	case 2:
		set("death_msg",CYN"\n$N说道：哎，被放到这里当菜板，还不许还手，我死得真冤啊！\n"NOR);
		break;
	}

	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void go(object me)
{
	init_me(me,4);
	message_vision("$N东倒西歪地走了过来。\n",this_object());
	switch (random(3))
	{
	case 0:
		message_vision(HIY"\n$N上下打量你一眼，嘿嘿冷笑道：也不过如此而已。\n\n"NOR,this_object());
		break;
	case 1:
		message_vision(HIY"\n$N睨了你一眼：小子，就凭你也想拦住我？\n\n"NOR,this_object());
		break;
	case 2:
		message_vision(HIY"\n$N大笑道：老夫乃$N，无知小儿，还不快滚！\n\n"NOR,this_object());
		break;
	}
}