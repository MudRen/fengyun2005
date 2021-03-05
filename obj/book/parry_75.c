// An example book

inherit ITEM;

void create()
{
	set_name("过招要旨" , ({ "parrybook" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍拆招卸力之法的入门书．\n");
        set("value", 0);
        set("skill", ([
                "name":         "parry",      
                "exp_required": 2000,       
                "sen_cost":     5,
                "difficulty":   15,  
                "max_skill":    74,
                "literate" : 	"parry",
		"liter_level":  50,
        ]) );
	::init_item();
}
 
