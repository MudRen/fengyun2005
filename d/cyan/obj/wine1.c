#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"百年泥香"NOR, ({ "wine" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一壶美酒。\n");
		set("unit", "壶");
        set("liquid", ([
        "type": "water",
        "name": "没有一点酒味的水",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

