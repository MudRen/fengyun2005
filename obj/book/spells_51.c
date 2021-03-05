 // annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("奇术观览", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                "这本旧书的纸张都已经泛黄了，上面记载的是天下各门各派的仙符奇术。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "spells",               
                        "exp_required": 100000,                 
                        "sen_cost":     10,
                        "difficulty":   20,     
                        "max_skill":    50
                ]) );
        }
        ::init_item();
}

