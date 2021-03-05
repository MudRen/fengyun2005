#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("尸体", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "随着各派尊长到明霞山参加饮血平寇大会的无不是百里挑一的精英，\n他们的武学造诣在江湖中通常已鲜有人及。\n然而，他已经死了，只剩下一具尸体静静地躺在这里。\n他的相貌吗... 都已经死了，还有什么好看的！\n\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}


