// book.c

inherit ITEM;

void create()
{
	set_name( "太极拳练功图", ({ "taiji-book", "book" }));
	set_weight(100);
	set("unit", "本");
	set("long", "这是武当派太极拳的入门练功图。\n");
	set("value", 1000);
	set("skill", ([
	    "name":                 "taiji",
	    "exp_required": 5000,                
	    "sen_cost":             40,     
	    "difficulty":   30,            
	    "max_skill":    20           
	]) );
	::init_item();
}
