// An example book

inherit ITEM;

void create()
{
	set_name("基本枪术" , ({ "spear book","book"}) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本霸王枪王老爷子留下来的基本枪法。\n");
        set("value", 500);
	set("no_drop", 1);
        set("skill", ([
                "name":         "spear",      
                "exp_required": 1000000,       
                "sen_cost":      2,
                "difficulty":   15,  
                "max_skill":    74,
               	"literate":		"spear",		
				"liter_level":	65,	     
        ]) );
        ::init_item();
}
 
