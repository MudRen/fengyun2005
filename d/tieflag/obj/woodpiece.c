
inherit ITEM;

void create()
{
        set_name("字迹不清的碎木片", ({ "woodpiece"}) );
        set_weight(30);
        
	set("unit", "片");
	set("long", "一片字迹不清的碎木片。\n");
    ::init_item();
}

