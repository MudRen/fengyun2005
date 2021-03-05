inherit ITEM;

void create()
{
	set_name("残破剑谱" , ({ "swordbook" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "一本残缺不全的剑谱，左边的一半已经被焚毁，因此每个招式都只剩下一半。\n");
        set("value", 1000);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("skill", ([
                "name":         "xiaohun-sword",      
                "exp_required": 1500000,       
                "sen_cost":       20   ,
                "difficulty":  30,  
                "max_skill":   10,
        ]) );
}
 
void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
	string book;
	int sena;
	
	object me=this_player();
	if(me->query("marks/离别钩",1))
		return 0;
        if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
    		    return 0;
        if(this_object()==present(book,me))
        {
		tell_object(me,"这本剑谱已经残破不全，无法从上面学到任何东西。\n");
		return 1;
	}
	return 0;
}
