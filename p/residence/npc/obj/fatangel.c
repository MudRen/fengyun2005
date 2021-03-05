#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR+"毁灭石像"+NOR, ({ "dismantle statue","statue" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("value",50000);
		set("unit", "个");
		set("long","一个石像，臃肿肥沉得可以砸烂各种东西。");
		set("desc_ext","砸毁家具(dismantle)");
	}
}

void init()
{
	if (environment() == this_player())	
	{
		add_action("do_dismantle","dismantle");
		set("value",0);
	}
}

int do_dismantle(string arg)
{
	if (!arg)
	{
		message_vision(CYN"$N扬起"+name()+NOR+CYN"在空中霍霍挥舞。\n"NOR,this_player());
		return 1;
	}
}