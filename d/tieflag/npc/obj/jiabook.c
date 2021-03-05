inherit ITEM;
void create()
{
	set_name("嫁衣神功",({ "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"一本绢册，上面写道：武道禅宗，嫁衣神功。\n");
		
        set("material", "cloth");
		set("skill", ([
			"name": 		"jiayiforce",	
			"exp_required":		50000,		
			"sen_cost":		60,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
    ::init_item();
}

