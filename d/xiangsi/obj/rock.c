// annie 07.2003
// dancing_faery@hotmail.com
inherit ITEM;

void create()
{
	set_name("石峰", ({ "石" , "石峰"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "一座形态奇诡的石峰，上面似乎隐约刻着什么文字。\n");
		set("value", 1);
        set("skill", ([
                "name":        "move", 
                "exp_required": 0,                  
                "sen_cost":     35,         
                "difficulty":   35,                 
				"literate" :    "move",
				"liter_level":  95,
                "max_skill":    95,
        ]) );
		}
    ::init_item();
}

int is_container() { return 1; }

// 1级的move
// yawn ^^
