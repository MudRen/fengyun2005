// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm

inherit ROOM;
void create()
{
        set("short", "老鼠洞");
        set("long", @LONG
    
[37m     
         (,).-"  ".			
        /',  _ (   )________,
        `^'"` """"'`
[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"mice_room2",
	]));
	set("item_desc",([
        	"down":	"洞下面黑咕隆咚什么也看不清，只有些悉悉索索的动静。\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/s_mice" : 1,
         ]) );
        
	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-10);
	setup();
}


int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"恶狠狠地扑了上来。\n");
		else
			message_vision("$N匍匐在地上向下钻去。。。。\n",me);
			return 1;
	}
	return ::valid_leave(me,arg);
}


        