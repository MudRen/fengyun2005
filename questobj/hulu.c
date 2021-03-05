#include <ansi.h>
#include <condition.h>
inherit ITEM;

void create()
{
    set_name(HIG "猴儿酒" NOR,({"wine-hulu"}));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "wood");
		set("long",
            GRN"一个翠绿色的酒葫芦，隐隐之中泛出柔和的光晕，里面盛满了猴儿酒。\n"NOR);
		}
    ::init_item();
}

void init()
{
	if(this_player()==environment())
	add_action("do_drink","drink");
}

int do_drink(string arg)
{
	object me;
	me = this_player();
	if (!arg)
		return notify_fail("你要喝什么？\n");
    if (arg != "wine-hulu")
		return notify_fail("你要喝什么？\n");
	if (query("used")) 
		return notify_fail(this_object()->name()+"已经被喝光了。\n");
    message_vision(HIC"$N捧起猴儿酒，咕嘟咕嘟畅饮起来......\n"NOR,me);
	me->clear_condition_type(LOW_POISON);
    message_vision(HIW"\n突然$N觉得腹中一热，不禁一张口，一道白练似的酒箭激喷而出......\n$N觉得如暮春风，浑身舒适无比。\n\n"NOR,me);
	set("used",1);
	return 1;
}
