inherit F_LIQUID;
inherit ITEM;

void create()
{
	set_name("热气腾腾的鲫鱼汤", ({ "hot soup" ,"soup"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的鲫鱼汤。\n");
		set("unit", "碗");
		set("value", 90);
		set("max_liquid", 50);
	}
        set("liquid", ([
                "type": "soup",
                "name": "鲫鱼汤",
                "remaining": 5,
                "drunk_apply": 0,
        ]) );

	::init_item();
}
int finish_drink()
{
        set_name("粗碗", ({"bowl"}));
	set("value",10);
        set("long", "一只粗瓷大碗。\n");
        return 1;
}
void init()
{
	::init();
	call_out("cold",100+random(100));
}

void cold()
{
	set_name("冷掉的鲫鱼汤", ({ "cold soup" ,"soup"}) );
	set("long", "一碗已经冷了的鲫鱼汤。\n");
}
