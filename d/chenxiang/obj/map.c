#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"藏宝图"NOR, ({ "map" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张皱皱的羊皮藏宝图，你可以读一读（ｒｅａｄ）．\n");
          }
	::init_item();
}

void init()
{
    	if(environment(this_object())==this_player()){
			add_action("do_read","read");
    		add_action("do_go","go");
		}
}

int markit(object me)
{
    	object design;
    	if(!query("already"))   	{
			design = new("/d/chenxiang/obj/design");
			tell_object(me,HIR"\n你一弯腰，从『藏宝图』所指示的地方挖出孔雀图！\n"NOR);
			if(!design->move(me))	design->move(environment(me));
			me->delete_temp("map_going");
			set("already",1);
    	}
    	return 1;
}

int do_read(string arg)
{
    	object me;
    	mapping exits;
    	string *dirs;
		string thisdir;
		if(arg != "map") return 0;
		
		me=this_player();
	
		if(me->query_temp("map_going") >= 10) {
			 markit(me);
			 return 1;
		}
		
		if( !mapp(exits = environment(me)->query("exits")) )    {
	        tell_object(me,"这儿地势不清，换个地方看看！\n");
	        return 1;
		}
	
		dirs = keys(exits);
		thisdir = dirs[random(sizeof(dirs))];
		set("thisdir",thisdir);
		if (!query("already")) 
			tell_object(me,"有一批宝藏就在"+thisdir+"的方向！你可以用 go "+thisdir+" 来寻找它。\n");
		else 
			tell_object(me,"孔雀图中的东西似乎被别人得到了。\n");
		return 1;
}

int do_go(string arg)
{
		
       	if (query("already"))	return 0;
       		
       	if(arg == query("thisdir") && query("thisdir") != "none") {
			this_player()->add_temp("map_going",1);
    	}	else
    	{	
    		this_player()->delete_temp("map_going");		
//    		tell_object(this_player(),YEL"走错了！只能重头开始了。\n"NOR);
    	}
    	set("thisdir","none");	
//    	tell_object(this_player(),"going is"+ this_player()->query_temp("going")+"\n");
    	return 0;
}

