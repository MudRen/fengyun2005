// force_book.c
inherit ITEM;
void create()
{
	set_name("内功心法", ({ "neibook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
			"提到一些呼吸吐纳方法。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name": 	"force",
			"sen_cost":	5,
			"difficulty":	10,
			"max_skill":	20
		]) );
	}
	::init_item();
}


