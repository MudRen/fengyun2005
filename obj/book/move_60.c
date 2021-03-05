// book2.c

inherit ITEM;
void create()
{
	set_name("旧竹片", ({ "bamboo", "shu", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long",
			"蝙蝠岛轻功入门篇\n"
			"这是一片两边去皮的旧竹片，正面和背面都画了无数个飞翔纵跃的小图形。\n");
			set("value", 10);
			set("material", "bamboo");
			set("skill", ([
			"name":	"move",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"sen_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59,	// the maximum level you can learn
			"literate" : 	"move",
			"liter_level":  55,
		
		]) );
	}
	::init_item();
}
