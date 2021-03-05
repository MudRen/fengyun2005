// water.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("白玉小马桶", ({"water"}));
    set_weight(700);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("long", "下了砒霜的\n");
	set("unit", "杯");
	set("value", 0);
	set("max_liquid", 100);
    }

    set("liquid", ([
	"type": "water",
	"name": "飘着东西的水",
	"remaining": 100,
      ]));
    ::init_item();
}

