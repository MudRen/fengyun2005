// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "长老院");
        set("long", @LONG
少林历代以来，除方丈外，还有四位护寺长老，武功必须绝高，且佛法精深，
四长老执掌僧监，维护少林安全和声誉，辈分不在方丈之下，据传现在这四位长老
是少林千年来最出色的四位，近五十年来还无人能逃出少林僧监。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jian",
  "southeast" : __DIR__"laos",
  "northeast": __DIR__"laon",
  "west":__DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/master_17_6" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

/*void init()
{
        if(this_player()->query_skill("daode",1) >= 10)
	set("exits/west",__DIR__"banruo");
	else
	delete("exits/west");

}*/


int valid_leave(object me,string dir)
{
    object ob;
	
	if(userp(me) && dir == "west" && ob=present("master deng",this_object()))
	{
		if (me->query_skill("daode",1)<10){
			message_vision("心灯对$N说：你还是先学点道德经吧。\n",this_player());
			return notify_fail("");
		}	
	}
	return 1;
}
