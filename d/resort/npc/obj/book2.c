// An example book

inherit ITEM;

void create()
{
	set_name("一剪梅花手秘笈" , ({ "meihua-shou" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍一剪梅花手的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "meihua-shou",      
                "exp_required": 200000,       
                "sen_cost":             30,
                "difficulty":   20,  
                "max_skill":    60     
        ]) );
}
 
