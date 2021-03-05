// annie 07.2003
// dancing_faery@hotmail.com

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(CYN"闻香瓶"NOR, ({ "bottle" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1000);
		set("material", "jade");
		set("long", "一个青色的小瓷瓶，瓶口封着橡木做的软塞。\n里面盛的据说是皓月天白山千鸟的香气，有提神之效。\n");
		set("desc_ext","提神(smell)");

	}
	::init_hammer(1);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_smell","smell");
}


int do_smell(string arg)
{
	int time;
	object me;
	me = this_player();
	if (!arg || arg != "bottle")
		return notify_fail("你要闻什么？\n");

	message_vision("$N取出一个小小的"CYN"闻香瓶"NOR"，拔开软木塞子轻嗅。\n",me);
	if (random(10))
	{
		tell_object(me,HIG"一缕醉人的馨香沁入了你的心中．．．\n"NOR);
		me->receive_heal("sen",20);
	}
	else
	{
		tell_object(me,HIG"一缕醉人的馨香沁入了你的鼻端．．．\n你的鼻子突然有些发痒，啊，啊，啊嚏！\n"YEL"糟糕，过敏了！\n"NOR);
		me->unconcious();
	}
	return 1;
}
