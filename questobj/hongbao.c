#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "红包" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，上面绣着：银钩赌场，黄。\n");
          }
    ::init_item();
}

void init()
{

	if(environment()==this_player())
		add_action("do_open","open");
}

int do_open(string arg)
{
	object gold;
	if(arg != "hongbao" && arg != "红包") return 0;
	if(query("opened"))
		return notify_fail("你打开小红包，但里面是空的！\n");
	gold = new("/obj/money/gold");
	gold->set_amount(2);
	gold->set("name","纯金叶子");
	gold->set("base_unit","张");
	gold->move(this_player());
	set("opened",1);
	return notify_fail("你打开小红包，从里面拿出几张纯金叶子！\n");
}
