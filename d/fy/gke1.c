inherit ROOM;
void create()
{
    set("short", "后厢房");
    set("long", @LONG
房间里布置很简单，只有一张小床，一个小几，和几张方凳。窗台上放着一个
磁杯，杯里插着几枝无名小花。房间虽不大，但是给人整洁舒适的感觉。这儿是金
狮镖局的镖师，趟子手和伙计们歇息的地方。从边门出去便是镖局的后院了。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"ginhall",
	"east" : __DIR__"backdoor",
      ]));
    set("objects", ([
	__DIR__"npc/resting_biao" : 2,
	__DIR__"npc/biaotou1" : 1,
      ]) );

    set("coor/x",220);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
