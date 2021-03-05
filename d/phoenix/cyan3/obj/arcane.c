
inherit ITEM;

void create()
{
	set_name("玄天推演图", ({"玄天推演图", "arcane graphics" ,"drawing" }) );
	set_weight(500);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "刻在地上的奇异图形，上面线条交错，不知是何含义。\n");
		set("value", 1);
        set("skill", ([
                "name":        "starrain", 
                "exp_required": 0,                  
                "sen_cost":     35,         
                "difficulty":   35,                 
				"literate" :    "starrain",
				"liter_level":  95,
                "max_skill":    95,
        ]) );
	}
    ::init_item();
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
