// movebook.c

inherit ITEM;

void create()
{
    	set_name("狼皮秘卷", ({ "wolfskin scroll","scroll" }));
    	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "一本年代久远的画卷，泛黄的纸上依稀可以看出画得都是些诡异的人像。\n");
        	set("value", 1);
		set("material", "paper");
		set("skill", ([
            		"name":         "wolf-curse", 
            		"exp_required": 200000,              
			"sen_cost":	20,				
			"difficulty":	20,		
            		"max_skill":    50      
		]) );
	}
	::init_item();
}
