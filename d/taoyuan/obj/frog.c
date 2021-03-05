inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("寒潭蛙", ({ "frog" }) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一只在阴暗处长大的墨绿色的青蛙，约有一指长。\n");
        set("unit", "只");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 60);
    }
    ::init_item();
}

