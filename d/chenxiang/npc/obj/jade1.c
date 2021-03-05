// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
    set_name("缅玉弧", ({ "round jade"}) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个用缅玉琢磨成的玉弧，大约有八寸宽，三分之一园。\n");
        set("unit", "块");
        set("value", 1000);
        set("wear_msg", "$N把一块$n戴在头上。\n");
        set("unwield_msg", "$N把$n从头上除了下来。\n");
        set("female_only", 1);
        set("need_fix",1);
    }
	::init_head();
}

void init()
{
    //if(this_player()==environment() && query("fixed"))
    add_action("do_combine","combine");
}

int do_combine()
{
    object me;
    object *inv;
    object ob;
    int i,sum=0;
    me = this_player(); 
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("id") == "round jade" && inv[i]->query("fixed"))  
            sum=sum+1;
   
    if(sum==3)
    {
        if (!me->query_temp("marks/王石匠")) {
        	tell_object(me,"这套缅玉弧似乎不是为你定做的，拼不起来。\n");
        	return 1;
        }	
        tell_object(me,"你将手中的三块缅玉弧合并成一个玉脖套。\n");
        for(i=0; i<sizeof(inv); i++)
            ob=new(__DIR__"botao");
        ob->set("armor_prop/jade_pro",1);
        ob->move(me);
        for(i=0; i<sizeof(inv); i++)
            if(inv[i]->query("id") == "round jade" && inv[i] != this_object())
                destruct(inv[i]);
        destruct(this_object());
        return 1; 
    }
    return 0;
}
