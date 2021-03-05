inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("青石碑", ({ "青石碑","石碑","bei","shibei","tomb"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", CYN"碑上几个醒目大字是：“神刀堂烈士之墓。”旁边还有几个人的名字：
“白天羽夫妻、白天勇夫妻，合葬干此。” \n"NOR);
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


