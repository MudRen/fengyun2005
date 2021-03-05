
inherit ITEM;

void create()
{
	set_name("九子鬼母像", ({ "ghostmother" , "mother"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "仔细观察石像，你发现一个伏在九子鬼母背上的婴儿手中，拿著一柄
长约七寸的短剑，剑头指向东面的山窟。\n");
		set("value", 1);
	}
}


