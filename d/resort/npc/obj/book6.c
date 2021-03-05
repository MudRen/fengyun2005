// An example book

inherit ITEM;

void create()
{
	set_name("内功心法秘笈" , ({ "force" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍内功心法的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "force",      
                "exp_required": 200000,       
                "sen_cost":             40,
                "difficulty":   30,  
                "max_skill":    100     
        ]) );
}
 
