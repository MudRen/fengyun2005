inherit ITEM;

void create()
{
	set_name("剑法进阶", ({ "sword book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这本旧书的纸张都已经泛黄了，像是经常被人翻阅，上面似乎写着\n"
			"一些剑法的口诀。\n");
		set("value", 0);
		set("material", "paper");
		set("no_transfer",1);
		set("skill", ([
			"name": 	"sword",	
			"exp_required":	100000,				
			"sen_cost":	5,				
			"difficulty":	10,		
			"max_skill":	74,
			"literate":	"sword",		
			"liter_level":	65,	
		]) );
	}
	::init_item();
}
