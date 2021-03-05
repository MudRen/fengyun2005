inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	string *names = ({ "大锦鲤", "小锦鲤" });
	i = random(2);
        set_name(names[i], ({ "fish" }) );
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一条锦鲤，身上鱼鳞的色彩就象天边的彩霞。\n");
                set("unit", "条");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

