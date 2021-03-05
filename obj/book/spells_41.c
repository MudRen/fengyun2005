// force_book.c

inherit ITEM;

void create()
{
	set_name("阴经", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
		"这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n提到一些采阳补阴方法什麽的。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name":	"spells",		
			"exp_required":	8000,			
			"sen_cost":	10,
			"difficulty":	20,	
			"max_skill":	40
		]) );
	}
	::init_item();
}
