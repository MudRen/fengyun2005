// spear_book.c

inherit ITEM;

void create()
{
	set_name("暗器简介", ({ "throwingbook","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "本");
		set("long",
			"这是本绢纸制的书，封面上隐约可见“暗器简介”四个蝇头小楷。\n"
			);
		set("value", 50);
		set("no_drop",1);
		set("material", "paper");
		set("skill", ([
			"name": 	"throwing",		
			"exp_required":	0,			
			"sen_cost":		2,				
			"difficulty":	10,				
			"max_skill":	49				
		]) );
	}
	::init_item();
}
