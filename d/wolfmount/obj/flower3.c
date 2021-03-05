#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
    set_name(HIG"雏菊"NOR, ({ "daisy" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一朵娇巧可人的雏菊。\n");
		set("unit", "朵");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);
		set("lore", 1);

	}
	::init_head();
}


void init(){

	if(this_player() != environment()) {
		add_action("do_get", "get");
	}
}


int flower_gone(){
	message_vision("$N缓缓凋谢了，化为飘落空中的花瓣。\n", this_object());
	destruct(this_object());
	return 1;
}

int do_get(string arg) {
	if (arg == query("id")) 
		call_out("flower_gone", 360);
	return 0;
}