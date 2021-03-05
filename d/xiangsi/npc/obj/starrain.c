// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("星海纵横", ({ "sky map","map" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
			"一张天图，上面绘的是天穹黄道，星汉罗行之路。\n星图的右下角标注着一个小小的＂昕＂字。\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":	"starrain",		
			"sen_cost":	10,
			"difficulty":	20,	
			"max_skill":	50,
		]) );
	}
	::init_item();
}


