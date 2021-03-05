// bottle.c
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name(HIW"汉白玉葫芦"NOR, ({ "white calabash", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "这是一个汉白玉制成的酒葫芦，隐隐散发出血红色的葡萄美酒的色泽。\n");
		set("unit", "个");
        set("value", 200);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
        "name": "葡萄美酒",
		"remaining": 60,
         "drunk_apply": 10,
	]) );
}
