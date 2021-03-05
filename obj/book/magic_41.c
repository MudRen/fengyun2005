// force_book.c

inherit ITEM;

void create()
{
	set_name("阳经", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
		"这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
			"提到一些采阴补阳方法什麽的。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name":	"magic",		
			"exp_required":	8000,			
			"sen_cost":	10,
			"difficulty":	20,	
			"max_skill":	40
		]) );
	}
	::init_item();
}
