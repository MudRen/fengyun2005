// movebook.c

inherit ITEM;

void create()
{
	set_name("残破古画", ({ "picture"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
			"这张都已经泛黄了残破古画，上面有一些小人\n"
			"摆出一些醉仙望月步的姿态。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"zuixian-steps",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	49		
		]) );
	}
}
