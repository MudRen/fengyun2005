// movebook.c

inherit ITEM;

void create()
{
        string *name= ({"法华经", "金光明经", "法句", "泥恒", "法海藏"});
        set_name( name[random(5)] , ({ "buddbook", "book" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"buddhism",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	15		
		]) );
	}
}
