
inherit ITEM;

void create()
{
	set_name("被石蛇缠住的恶人像", ({ "eren" , "statue"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "这是一具被石蛇缠住的恶人像。跟其它石像一样雕刻的栩栩如生。仔细
看上面似乎有被人触摸（ｔｏｕｃｈ）过的痕迹。\n");
		set("value", 1);
	}
}



