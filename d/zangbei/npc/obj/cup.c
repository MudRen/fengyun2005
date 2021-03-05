inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
    	set_name(HIB "紫藤杯" NOR,({"cup"}));
    	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个紫藤酒杯。\n");
		set("unit", "个");
        	set("value", 0);
        	set("max_liquid", 10);
	}
	set("liquid", ([
        	"type": "alcohol",
        	"name": "葡萄酒",
		"remaining": 5,
        	"drunk_apply": 20,
	]) );
}
