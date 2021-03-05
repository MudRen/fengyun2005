inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("黄山石耳", ({ "shi er", "黄山石耳" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "体呈叶状，背面灰绿色，腹面中央有脐状突出物。\n");
                set("unit", "些");
                set("value", 400);
                set("food_remaining", 5);
                set("food_supply", 10);
        }
	::init_item();
}

