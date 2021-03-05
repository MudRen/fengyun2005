inherit ITEM;
void create()
{
        set_name( "游水入门", ({ "swimmingbook" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是几张记载着狗刨式水术的油纸。\n");
        set("value", 100);
        set("skill", ([
                "name":        "swimming", 
                "exp_required": 0,                  
                "sen_cost":     5,         
                "difficulty":   3,                 
                "max_skill":    30,                  
        ]) );
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

