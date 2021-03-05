inherit ROOM;
void create()
{
    set("short", "镖局厢房");
    set("long", @LONG
房间里布置很简单，只有一张小床，一个小几，和几张方凳。窗台上放着一个
磁杯，杯里插着几枝无名小花。房间虽不大，但是给人整洁舒适的感觉。这儿是金
狮镖局的镖师，趟子手和伙计们歇息的地方。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ginhall",
      ]));
    set("objects", ([
	__DIR__"npc/resting_biao" : 2,
	__DIR__"npc/biaotou3" : 1,
      ]) );
    set("coor/x",200);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
