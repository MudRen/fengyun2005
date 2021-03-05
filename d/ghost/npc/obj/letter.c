
inherit ITEM;

void create()
{
        set_name("顾云飞的秘函", ({ "letter"}) );
        set_weight(30);
        set_max_encumbrance(80);
	set("unit", "封");
	set("long", "顾云飞送给武当掌门的秘函。\n");
	::init_item();
}

