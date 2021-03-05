// book.c

inherit ITEM;

void create()
{
        set_name( "占卜入门", ({ "book" }));
        set_weight(100);
        set("value", 10000);
        set("unit", "本");
        set("long", "这是一本讲解占卜学的书籍。\n");
        set("skill", ([
                "name":                 "foreknowledge",
                "exp_required": 	0,                
                "sen_cost":             5,     
                "difficulty":   	30,            
                "max_skill":    	49
                                            
        ]) );
	::init_item();
}
