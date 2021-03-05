inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "浸龙走廊");
    set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花异草。滚
滚热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要扶着栏杆才不会滑
倒。
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlonglang2",
	"north" : __DIR__"jlongpool",
      ]));
    set("objects", ([
	__DIR__"npc/smilegirl": 1,
      ]) );
    set("coor/x",-80);
    set("coor/y",-145);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("north", "door","檀木门", "south", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    int weartowel=0;
    
    if( dir == "north" && ob=present("chu chu", this_object()))
    {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{    
		    if( (string)(inv[i]->query("id")) == "white towel" ){
					withtowel = 1;
					if (inv[i]->query("equipped"))
						weartowel = 1;
			}
		}
		if( !withtowel)
	    	return notify_fail("楚楚向你笑道：没有白毛巾怎么洗？\n");
    	if (!weartowel)
			return notify_fail("楚楚向你笑道：还是围上毛巾再进去吧，不要吓到别人．\n");
	}
	
    if( dir == "south" && ob=present("chu chu", this_object()))
    {
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
	    if( (string)(inv[i]->query("id")) == "white towel")
	    {
		tell_object(me,ob->name()+"笑咪咪的将你身上湿的"+
		  inv[i]->name()+"拿了回去．\n\n\n");	
		destruct(inv[i]);
	    }
	}


    }
    return ::valid_leave(me, dir);
}

