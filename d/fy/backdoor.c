#include <room.h>
inherit DOOR_ROOM;
void create()
{
    set("short", "镖局后院");
    set("long", @LONG
这里是金狮镖局的后门，平时总是关得严严实实，只有当镖局接到什么秘密而
贵重的红货后，才由镖局里的一等一的镖头从后门悄悄离开。因此这里的看守也异
常严密，有些不知情况的流浪汉糊里糊涂闯进这里，结果被象死狗一样扔到水沟里，
再也爬不出来了。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"gke1",
	"north" : __DIR__"ecloud4",
      ]));
    set("objects", ([
	//        __DIR__"npc/resting_biao" : 2,
	//        __DIR__"npc/biaotou1" : 1,
      ]) );
    set("coor/x",240);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("north", "door","后门", "south", DOOR_CLOSED);
}
