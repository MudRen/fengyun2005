// An example book

inherit ITEM;

void create()
{
	set_name("风尘简" , ({ "fengchen book", "book" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一册沉甸甸的竹简，乃风尘三侠之虬髯客游历海内诸国后呕心沥血写就。 
包罗万象，深奥无比。 \n");
        set("value", 10000);
        set("no_drop", 1);
        set("no_get", 1);
        set("no_sell", 1);
        set("skill", ([
                "name":                 "magic",      
                "exp_required": 200000,       
                "sen_cost":             10,
                "difficulty":   20,  
                "max_skill":    99,     
        ]) );
}
 
