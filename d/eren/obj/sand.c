inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("黄沙", ({ "沙" , "sand","desert"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "无边无际的黄沙地，少有起伏，仔细看去，似乎还有爬虫经过的痕迹。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


