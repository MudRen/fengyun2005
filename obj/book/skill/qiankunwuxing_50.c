// movebook.c

inherit ITEM;

void create()
{
	set_name("罗刹牌", ({ "luosha" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
        set("for_bandit",1);
		set("long",	"这块真罗刹牌通体莹白，神魔之像栩栩如生，下面一排小字，
刻得正是乾坤无形的练气法门。\n");
		set("no_drop", 1);
		set("value", 200);
		set("material", "stone");
		set("skill", ([
			"name": 	"qiankunwuxing",	
			"exp_required":	600000,				
			"sen_cost":	2,				
			"difficulty":	5,		
			"max_skill":	49,		
		]) );
	}
	::init_item();
}
