inherit ROOM;
void create()
{
        set("short", "青石小路");
        set("long", @LONG
这是一条青石小路，两边种满了花卉，还有些药材，显得非常的幽静，向前是
长长的青石路，小路一端的尽头似乎有一道小圆门，路两侧是几间房子，正是清平
弟子的卧室所在，八大弟子分住南北两间。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"aroad",
  "north" : __DIR__"bedroom1",
  "south" : __DIR__"bedroom2",
   ]));

   	set("outdoors","qingping");
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
