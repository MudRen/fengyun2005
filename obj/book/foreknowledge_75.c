inherit ITEM;

void create()
{
        set_name("好运连连", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","司空摘星：为人处事，运气第一，若无运气，便有晦气！\n");
                set("value", 200);
                set("no_drop",1);
                set("material", "paper");
                set("skill", ([
                        "name": "foreknowledge",               
                        "exp_required": 20000,                 
                        "sen_cost":     5,
                        "difficulty":   20,     
                        "max_skill":    74,
                        "literate":	"foreknowledge",
						"liter_level":	60,
                ]) );
        }
        ::init_item();
}

