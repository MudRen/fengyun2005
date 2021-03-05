// wine.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("酒杯", ({"wine"}));
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
	"type": "alcohol",
	"name": "最劣的白酒",
	"remaining": 100,
	"drunk_apply": 5,
      ]) );
    ::init_item();
}
