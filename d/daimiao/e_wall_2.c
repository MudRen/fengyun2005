#include <room.h>
inherit ROOM;

void create()
{
  set("short","墙外小道");
  set("long",@LONG
岱庙方圆数里，四周皆有城墙，墙高三长，上有角楼、门楼。墙外是野草地，
风过簌簌作响，颇是荒凉，原本少有人至。只是近年来西方神教在岱庙建立总坛后，
寻常人等难以进入，想上泰山也只有从城墙外绕路了。
LONG
  );
  	set("exits",([
        	"north":__DIR__"e_wall_3",
         	"south":__DIR__ "donghua",
        ]));
        set("objects", ([
        	__DIR__"npc/daoshi":	3,
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  	
}
