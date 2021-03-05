// Room: dong0
inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "小径");
        set("long", @LONG
一条五色彩石小径直通精舍，两旁种满鲜花，五彩缤纷。路边更有各种果树，
果已熟透，甚为诱人。一扇玉门在阳光下份外可爱。
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
 		 "eastup" : __DIR__"gu3",
  		"westdown" : __DIR__"gu5",
 
	]));
	set("outdoors","tieflag"); 	
   	create_door("westdown","door","玉门","eastup",DOOR_CLOSED);         
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",20);
	setup();

}
void init()
{
	add_action("do_get","pick");
} 	  

int do_get(string arg)
{
        object swo;
	if( query("mark/been_get")>10) return notify_fail("果子已被摘光了。\n");
        if(random(1000)>1) 
        { 
		swo=new(__DIR__"obj/yiguo");
		swo->move(this_player());
		add("mark/been_get",1);
		write("你从树上摘了一个果子。\n" );
	}
	else
        { 
		swo=new(__DIR__"obj/yiguo1");
		swo->move(this_player());
		add("mark/been_get",1);
		write("你从树上摘了一个果子. \n" );
	}
        
        return 1;

}
void reset()
{
    	::reset();
	delete("mark/been_get");
}
