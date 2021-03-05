
inherit ITEM;

void create()
{
	set_name("一池清水", ({ "water" }) );
	set_weight(500);
	set("no_get","水是用＂打＂的，不是用＂拿＂的！\n");
    ::init_item();
}

