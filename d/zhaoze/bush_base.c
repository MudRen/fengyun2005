#include <ansi.h>

inherit ROOM;

int do_cut(string arg)
{
        object obj, me;
        string dir;
        
        
        if(!arg || arg=="")
        {
                write("你要砍开什么？\n");
                return 1;
        }
        if( arg == "bush" || arg == "荆棘" )
	{
		me = this_player();
		obj = me->query_temp("weapon");
		if( !obj ) 
		{
			write("你空着手，怎么砍？\n");
			return 1;
		}
		if( obj->query("jungle"))
		{
			if( !query("exits/"+query("route"))) {
        			set("exits/"+query("route"), query("route_room"));			
				switch(query("route")) {
					case "south": arg = "南"; break;
					case "east" : arg = "东"; break;
					case "north": arg = "北"; break;
					case "west":  arg = "西"; break;
				}
								
				message_vision(sprintf("$N用手中的%s砍出一条向"+arg+"的路。\n",obj->name()),me);
			}
			else
				message_vision(sprintf("$N用手中的%s砍向路边的荆棘。\n",obj->name()),  me);
		}
		else
 			message_vision(sprintf("$N用手中的%s向丛生的荆棘一顿乱砍。\n",obj->name()),me);
 		me->perform_busy(1);
	}
	else
	 	write("你要砍开什么？\n");
        return 1;
}

void init()
{	object ob,room;
	if( interactive( ob = this_player())) {
    		if(ob->query_skill("force",1) < 150) {
			if (!room=find_object(__DIR__"edge.c"))
				room = load_object(__DIR__"edge.c");
			ob->move(room);
			tell_object(ob, HIR"你被丛林里的灼热气焰冲了回来（需150级基本内功）\n\n"NOR);
		}else if (userp(ob) || userp(ob->query("possessed")))
				ob->apply_condition("zhaoze",10);			
	}
	add_action("do_cut","chop");
}

void reset()
{
	::reset();
        delete("exits/"+query("route"));
}

int valid_leave(object me, string dir)
{
        object ob;
        if (query("exits/"+query("route")) && dir == query("route"))
        if (ob = present("fire giant", this_object()))
        	return notify_fail(ob->name()+"挡住了你的去路。\n");        
	return 1;
}

