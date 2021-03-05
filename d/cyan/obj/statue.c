
inherit ITEM;

void create()
{
	set_name("观世音菩萨像", ({"观世音菩萨像", "菩萨像" ,"statue" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
		set("long", "一尊庄容肃穆的千手观世音菩萨像，与平常所供的观音稍有不同。\n");
		set("value", 1);
        set("skill", ([
                "name":        "chanting", 
                "exp_required": 0,                  
                "sen_cost":     35,         
                "difficulty":   35,                 
				"literate" :    "chanting",
				"liter_level":  95,
                "max_skill":    95,
        ]) );
	}
    ::init_item();
}

int is_container() { return 1; }

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
