// spells_book.c

inherit ITEM;

void create()
{
        set_name("符咒入门", ({ "spellsbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",                        
"这是一本符咒简介，里面画着一些稀奇古怪的符号,
学习此书可以提高咒术(spells)。\n"
                );
                set("value",200);
                set("material", "paper");
                set("skill", ([
                        "name":     	"spells",   
                        "exp_required": 100, 
                        "sen_cost":  	5, 
                        "difficulty":  	10,
                    	"max_skill":  	20

                ]) );
        }
        ::init_item();
}
 
