inherit ITEM;
inherit F_LIQUID;

int tianyi();

void create()
{
	set_name("铁锅", ({ "guo"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "锅里还在冒着热气，散发出一阵阵肉香。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "肉汤",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
	set("liquid/drink_func",(: tianyi() :));
	::init_item();
}


int tianyi(){
	this_player()->apply_condition("tianyi",20);
	return 1;
}