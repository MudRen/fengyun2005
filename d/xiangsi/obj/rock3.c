// annie 07.2003
// dancing_faery@hotmail.com
//萧青湘
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("两界碑", ({ "两界碑" , "界碑", "碑"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", "两界碑上被人用纯罡指力刻着：\n\n　"HIR"百年人生无二命　此去死亡路一条\n\n　　　　　　　　　　定元六年摩南答刻"NOR"\n\n算来，这块碑文所刻的已经是数百年前的事情了。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
