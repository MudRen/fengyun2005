inherit COMBINED_ITEM;
void create()
{
	set_name("梅树幼苗", ({ "tree", "plum tree" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","又软又轻的树苗，也许你可以用来造（ｍａｋｅ）些东西．\n");
		set("unit", "捆");
		set("base_unit", "根");
		set("base_weight", 10000);
		set("base_value", 1);
	}
	set_amount(1);
}


void init()
{
    if(this_player()==environment()) {
        	add_action("do_make","make");
    }
}


int do_make()
{
	object boat;
	string msg;

	if(query_amount() < 15)
		return notify_fail("造小木筏至少需要15根木材。\n");
	seteuid(getuid());
	boat = new(__DIR__"boat");
    
    msg = "$N用灵巧的双手造出了一只小木舟";
    if(!boat->move(this_player()))
    {
    	boat->move(environment(this_player()));
    	msg += "放在身边。\n";
    } else
    	msg +="。\n";
    message_vision(msg, this_player());
	destruct(this_object());
	return 1;
			
}
