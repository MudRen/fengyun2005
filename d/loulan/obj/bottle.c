inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIC"【孔雀开屏】"NOR, ({"peacock"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "由天下七大美酒混合调出来的美酒，闻之便令人有醺醺之意。\n");
                set("unit", "瓶");
                set("value", 0);
                set("max_liquid", 100);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "孔雀开屏",
		"remaining": 100,
		"drunk_apply": 1,
	]) );
//	::init_item();
}