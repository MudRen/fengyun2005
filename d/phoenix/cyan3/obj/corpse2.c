#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("船仓直原的尸体", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "船仓直原 (Samurai)\n然而，他已经死了，只剩下一具尸体静静地躺在这里。\n他的相貌吗... 都已经死了，还有什么好看的！\n\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}


