// magic_book.c

inherit ITEM;

void create()
{
        set_name("魔法简介", ({ "magicbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",                        
"这是一本魔法入门，里面说了一些稀奇古怪的和一般的武学不同的东西，
学习此书可以提高法术（magic）\n"
                );
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name":     "magic",
                    	"exp_required": 100,
                        "sen_cost":  	5, 
                      	"difficulty":  	10,
                       	"max_skill":  	20 
                ]) );
        }
	::init_item();
}
 
