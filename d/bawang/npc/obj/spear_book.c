// An example book

inherit ITEM;

void create()
{
	set_name("基本枪术" , ({ "spear book","book"}) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本霸王枪王老爷子留下来的基本枪法。\n");
        set("value", 500);
	set("no_get", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_burn", 1);
        set("skill", ([
                "name":                 "spear",      
                "exp_required": 1000000,       
                "sen_cost":             20,
                "difficulty":   15,  
                "max_skill":   100     
        ]) );
        ::init_item();
}
 
