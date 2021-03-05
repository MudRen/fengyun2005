// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{       
	object          con, item;
        set("short", "精舍前");
        set("long", @LONG
此处一片空旷，浅草如茵，整齐如剪。一片新绿之上，罗列着十数件白玉色的
琴几，玉墩，棋案之属。红尘间的烟火喧嚷，似乎早以被群山所阻。
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  		"eastup" : __DIR__"gu2",
  		"westdown" : __DIR__"gu4",
 
	])); 
	set("objects", ([
                __DIR__"obj/qinji" : 1,
        ]));

	set("outdoors","tieflag"); 		
         
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",30);
	setup();

}



void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        
        con = present("qinji",this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/yaoqin");
                item->move(con);
        }
        
}
