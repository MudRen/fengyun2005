#include <armor.h>
inherit HEAD;

void create()
{
	set_name("天竺葵", ({ "flower" }));
	set_weight(30);
	if( clonep() ){
		set_default_object(__FILE__);
	} else {
		set("unit", "枝");
		set("long","一支天竺葵正开的灿烂。\n");
		set("value", 50);
		set("material", "wood");
	}
	::init_head();
}

void init() {
	if (!query("in_decay")) {
		set("in_decay",1);
		call_out("badmeal", 180);
	}	
}

void badmeal() {
	set("long", "枯萎了的一朵小花。\n");
	set("name", "干枯的天竺葵");
	set("value", 0);
}