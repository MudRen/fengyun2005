inherit ITEM;

void create()
{
	set_name("哈波特秘籍", ({ "magicbook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",	"这本书是哈·波特，也就是哈哈儿早年学习魔法的心得。\n");
		set("no_drop",1);
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":	"magic",		
			"exp_required":	0,			
			"sen_cost":		2,
			"difficulty":	20,	
			"max_skill":	74,
			"literate":	"magic",
			"liter_level":	60,
		]) );
	}
	::init_item();
}
