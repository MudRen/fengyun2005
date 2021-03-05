#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "石室");
        set("long", @LONG
四面的石壁之上都嵌着一盏石灯，燃着碧绿的火光，照亮了整个石牢。石牢只
有一半是石地，还有一半是潮湿的泥土。石地用石块组成，与泥上相接的部份参差
不齐，仿佛铺到那里石块便已经用尽。石地有两张石榻，之间隔着一张石桌，旁边
还有两张石凳。石凳上没有人，石榻上却有，一张石榻一个，总共两个人。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"basement2",
	]));
	set("objects", ([
 		__DIR__"obj/table2": 1,              	
 		__DIR__"obj/skeleton": 1,   
    	]) );
        set("no_fly",1);
        set("item_desc", ([
		"石榻": "石榻上那两个根本已不能叫做人。那只是两具死人骨骼，两具骷髅。\n",
		"bed": "石榻上那两个根本已不能叫做人。那只是两具死人骨骼，两具骷髅。\n",
		"人":  "石榻上那两个根本已不能叫做人。那只是两具死人骨骼，两具骷髅。\n",
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


void reset()
{
	object *inv;
        object table,skeleton,item1;
        int i,rice,cap; 
        ::reset();
        
        table = present("table", this_object());
        inv = all_inventory(table);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("id")=="parchment") rice=1;
        }
        if (!rice) {
        	item1 = new(__DIR__"obj/parchment");
        	item1->move(table);
        	}
        
        skeleton = present("skull", this_object());
        inv = all_inventory(skeleton);
        for (i=0;i<sizeof(inv);i++) {
        	if (inv[i]->query("id")=="crown") cap=1;
        }
        if (!cap) {
        	item1 = new(__DIR__"obj/crown");
        	item1->move(skeleton);
        }
}


