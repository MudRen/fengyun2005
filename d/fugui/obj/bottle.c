inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIG"酒坛"NOR, ({"jiutan"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个青瓷酒摊，花纹精细，里面想来装的也是美酒。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 10);
        }

	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 1500,
		"drunk_apply": 6,
	]) );
	::init_item();
}
