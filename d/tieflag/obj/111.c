#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("箱子", ({ "woodcase" , "case"}) );
    set_weight(500);
    set_max_encumbrance(40000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "个");
	set("long",
	  "这是一个普普通通的箱子。你可用它（make）或（remake）兵器。\n");
    }
    ::init_item();
}
int is_container() { return 1; }
void init()
{
    add_action("do_make","make");
}

int do_make(string arg)
{
    object me;
    object obj;
    me=this_player();
    if(environment()==this_player() && (int) this_player()->query("sen")>250)
    {               
	if(!arg) return 0;
	{
	    if(arg=="axe")        {obj=new(__DIR__"cmaxe");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把斧。\n");destruct(this_object());}
	    if(arg=="blade")      {obj=new(__DIR__"cmblade");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把刀。\n");destruct(this_object());}             
	    if(arg=="dagger")     {obj=new(__DIR__"cmdagger");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把匕首。\n");destruct(this_object());}
	    if(arg=="claw")       {obj=new(__DIR__"cmclaw");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一个爪子。\n");destruct(this_object());}
	    if(arg=="hammer")     {obj=new(__DIR__"cmhammer");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把锤。\n");destruct(this_object());}
	    if(arg=="staff")      {obj=new(__DIR__"cmstaff");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把杖。\n");destruct(this_object());}   
	    if(arg=="sword")      {obj=new(__DIR__"cmsword");obj->move(me);  
		write("你将手中的箱子打开，用其中的零件拼成了一把剑。\n");destruct(this_object());}
	    if(arg=="whip")       {obj=new(__DIR__"cmwhip");obj->move(me);
		write("你将手中的箱子打开，用其中的零件拼成了一把鞭。\n");destruct(this_object());}             
	    else tell_object(me, "你要做什么武器？\n");
	}
	return 1;
    }
    return 0;
}          
