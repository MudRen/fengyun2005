// An example book

inherit ITEM;

void create()
{
	set_name("短歌刀法秘笈" , ({ "shortsong-blade" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍短歌刀法的武功秘笈\n");
        set("value", 0);
        set("skill", ([
                "name":                 "shortsong-blade",      
                "exp_required": 200000,       
                "sen_cost":             40,
                "difficulty":   30,  
                "max_skill":    60     
        ]) );
}
 
