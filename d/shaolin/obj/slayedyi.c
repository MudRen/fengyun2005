inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("少林寺 第十八代长老「"+HIM"藏经楼首座"NOR+"」一铁的尸体", ({ "yitie's corpse"}) );
    	set_weight(800000);
    	set_max_encumbrance(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
        set("long", "少林藏经楼首座，数十年来未下藏经楼一步
然而，他已经死了，只剩下一具尸体静静地躺在这里。。。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
