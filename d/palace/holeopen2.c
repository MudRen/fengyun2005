inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "洞穴口");
        set("long", @LONG
光线透过洞口照了进来，然而你目力能及的只有洞口四周，方圆一两丈内的景
物。其余的一切皆笼罩在一片无边的黑暗之中。没有照明的东西，再向前走，只怕
会凶多吉少。这时候你多么希望有什么东西可以照明亚。     
LONG
        );
        set("exits", ([ 
		"enter" : __DIR__"darkhole",
		"out" : __DIR__"whiterock",
	]));
	set("outdoors","fengyun");
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",30);
	setup();
}


int 	light_notify(object lighter, int num)
{
		object me, room;
		
		me = this_player();
		
		write(WHT"你借着" + lighter->name()+ NOR WHT"发出的光，仔细观察起洞里的地形。\n"NOR);	
		
		me->add_temp("block_msg/all",1);
		if (!room = find_object(__DIR__"lighthole"))
			room = load_object(__DIR__"lighthole");
		me->move(room);
		me->add_temp("block_msg/all",-1);
		
		return 1;
}

/*
	
	


int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

	if( userp(me) && dir == "enter" ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->name() == "夜明珠") {
				me->move(__DIR__"lighthole");
				return notify_fail(HIY"\n你从怀里掏出夜明珠，借着夜明珠发出的光，钻进了洞！\n"NOR);
			}
                }
        }
	return 1;
}

*/
