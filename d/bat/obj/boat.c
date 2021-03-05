#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "木筏", ({ "boat" }) );
    set("unit", "块");
    set("value",0);
    set("no_get",1);
    set("long","一个木筏，可以用来航海（sail）\n");
    set_weight(150000);
	set("no_stack",1);
    ::init_item();
}

void init()
{
    add_action("do_sail","sail");
}

int do_sail(string arg)
{
    	if (!arg || arg == "boat" || arg == "木筏") {
    		message_vision(HIY"$N坐在木筏上向海中漂去．．．\n"NOR,this_player());
    		tell_object(this_player(),HIY"过了很久，终于到了岸边。\n"NOR);
    		this_player()->move(AREA_EASTCOAST"fchuan");
    		return 1;
    	}
    	write("你想驾驶什么？\n");
    	return 1;
}
