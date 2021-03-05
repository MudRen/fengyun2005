inherit ITEM;

void create()
{
	set_name("掌法进阶", ({ "unarmed book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这本旧书的纸张都已经泛黄了，像是经常被人翻阅，上面似乎写着\n"
			"一些掌法什麽的口诀。\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name": 	"unarmed",	
			"exp_required":	100000,				
			"sen_cost":	10,				
			"difficulty":	20,		
			"max_skill":	70		
		]) );
	}
	::init_item();
}
