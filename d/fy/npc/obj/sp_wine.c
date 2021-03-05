inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIC"【山鸡开屏】"NOR, ({"wine"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一瓶私酿的美酒，闻之便令人有醺醺之意。\n");
                set("unit", "瓶");
                 set("value", 10000);
                set("max_liquid", 100);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "山鸡开屏",
		"remaining": 100,
		"drunk_apply": 1,
	]) );
//	::init_item();
}
