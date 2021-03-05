inherit ROOM;
void create()
{
        set("short", "练武场");
        set("long", @LONG
这是一间宽大的练武场，十八般兵器样样齐全，还有几个练功用的木桩。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
       "east" : __DIR__"room7",
	]));
    set("objects", ([
      __DIR__"obj/wood": 1,
	  ]) );
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
