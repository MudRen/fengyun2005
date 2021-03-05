#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("针线包" NOR, ({ "needle bag","bag" }) );
    set_weight(800);
    set_max_encumbrance(800);
			if( clonep() )
            set_default_object(__FILE__);
    else {

            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的针线包，上面绣着：阳明幽径，江。\n");
			set("value",3000);
			set("closed", 1);
		  }
    ::init_item();
}

void init()
{
	if(environment()==this_player())
		add_action("do_open","open");
}

int is_container() {return 1;}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}


int do_open(string arg)
{
	object gold;
	if(arg != "bag" && arg != "needle bag" && arg != "针线包") return 0;
	if(!query("closed"))
		return notify_fail("你打开针线包，但里面是空的！\n");
	if (!this_player()->query("m_success/五行铜人"))
		return notify_fail("你打开针线包，发觉里边是几根五颜六色的银针。\n你似乎还用不到这些东西。\n");

	set("closed",0);
	set("value", 0);
	gold = new(__DIR__"sp_needle");
	gold->set("name","淡红色的细针");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","淡绿色的细针");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","淡黄色的细针");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","淡白色的细针");
	gold->move(this_object());

	gold = new(__DIR__"sp_needle");
	gold->set("name","淡黑色的细针");
	gold->move(this_object());

	return notify_fail("你打开针线包，发觉里边是几根五颜六色的银针。\n你一转念，突然想起兴国禅寺似乎正巧用得到它们。\n");
}
