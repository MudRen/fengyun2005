inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大嘴居");
        set("long", @LONG
这是件普通的农家小屋，东墙上靠着几间农具，门口贴着幅褪了色的对联，上
面歪歪扭扭地写着：“花香草香不如肉香，天好地好还是家好“。屋里正中是个火
坑，上面吊着个突突冒气的大锅，锅里不知煮着什么，老远就能闻到香味。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad2",
	"east" : __DIR__"dazuiju2",
	]));
        set("objects", ([
        	__DIR__"obj/guo": 1,
	]) );
	set("coor/x",40);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();

}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("guo", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        	item = new(__DIR__"obj/meat");
        	item->move(con);
        }
}