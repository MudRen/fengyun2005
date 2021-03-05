// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"赦免令"NOR, ({ "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "缇萦日思夜想的就是为了这张纸，现在她的付出终于有了\n回报。\n");
		set("value", 200);
		set("no_split",1);
		set("unit", "卷");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);
	}
	::init_item();
}


// by hippo 2009.11

