#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"知府印章"NOR, ({ "yinzhang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "方");
		set("material", "stone");
        	        set("long", @LONG
一方镶着金边的知府大印，可以在文书上盖章（ｓｅａｌ）。
一块隐隐透著寒气的白玉，虽然时间已在它的身上刻划下了岁月的痕迹，
可能因为吸收了代代持有者的人气，它的外表渐渐圆润了起来，光泽也
慢慢变得温和而内敛，特别显出它的地位和不凡。一面刻著几个古老的
篆文，经过长久的使用后，已经模糊的辨认不出文字的分界线，但是从
来没有任何人怀疑过它代表的权力与威信。
LONG);
	}
	::init_item();
}

void init()
{
        add_action("do_seal", "seal");
}

int do_seal(string arg)
{
	object obj;

	if (environment(this_object())!=this_player())
		return 0;
	if (!arg)
		return notify_fail("你要在哪里盖印？\n");
	if (!objectp(obj=present(arg,this_player())))
		return notify_fail("你要在什么地方盖印？\n");
	if (obj==this_object())
		return notify_fail("你不能在印章本身上盖印。\n");
	
	message_vision("$N对"+this_object()->query("name")+"呵了口气，在"+obj->query("name")+"上小心翼翼地盖上一个印章。\n",this_player());
	obj->set("sealed",1);

	return 1;
}
