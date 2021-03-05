// An example book

inherit ITEM;

void create()
{
	set_name("秋风步法秘笈" , ({ "fall-steps" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍秋风步法的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "fall-steps",      
                "exp_required": 200000,       
                "sen_cost":             30,
                "difficulty":   20,  
                "max_skill":    60     
        ]) );
}
 
