// An example book

inherit ITEM;

void create()
{
	set_name("棋道秘笈" , ({ "qidaoforce" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍棋道的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "qidaoforce",      
                "exp_required": 200000,       
                "sen_cost":             50,
                "difficulty":   40,  
                "max_skill":    60     
        ]) );
}
 
