inherit ITEM;
void create()
{
	set_name("纵横之术", ({ "perception-book","perception" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",	"一本手抄的薄薄纸书，字迹凌乱不堪。\n你凝神看去，上面所记载的却是极深的武功。\n");
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("value",10000);
		set("material", "paper");
		set("skill", ([
			"name": 	"perception",
			"sen_cost":	4,
				"literate":	"perception",
		"liter_level":	110,
			"difficulty":	2,
			"max_skill":	119
		]) );
	}
	::init_item();
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

