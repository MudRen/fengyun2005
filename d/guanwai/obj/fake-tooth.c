
#include <armor.h>

inherit HEAD;



void create()
{
	set_name("舍利子", ({ "tooth" , "budda-tooth"}) );
	set_weight(1);
	set("nature", "fake");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是僧人们认为有重要宗教意一的舍利子。\n");
		set("value", 5);
                set("wear_msg", "$N把$n戴在脖子上。\n");
                set("unwield_msg", "$N把$n从脖子上除了下来。\n");

	}
	::init_item();
}



