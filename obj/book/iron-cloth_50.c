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
		set("long","佛教经文，奇怪的是在页缝之间居然还有些健身的法门。\n");
		set("value", 70);
		set("no_transfer",1);
		set("material", "paper");
		set("skill", ([
			"name": 	"iron-cloth",	
			"exp_required":	0,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	49		
		]) );
	}
}
