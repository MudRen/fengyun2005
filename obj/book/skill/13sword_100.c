
inherit ITEM;

void create()
{
	set_name("削断的梅枝", ({ "meizhi"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "段");
		set("long",
                        "一段两三尺长的梅枝，似乎是被什么利器削断。然而断口处很长， 
几乎是平行着这根梅枝削下来的。梅枝上墨痕点点，似乎有人用墨迹标明了剑势的来龙去脉。\n");
                
		set("value", 700);
		set("material", "paper");
		set("no_sell",1);
		set("no_get",1);
		set("no_drop",1); 
		set("skill", ([
			"name": 	"13-sword",	
			"exp_required":	2000000,		
			"sen_cost":	10,	
			"difficulty":	5,	
			"max_skill":	99,
			"liter_level":  50,
		]) );
	}
		::init_item();
}
