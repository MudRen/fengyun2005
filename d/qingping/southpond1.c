//XXDER
inherit ROOM;
void create()
{
        set("short", "池塘");
        set("long", @LONG
这里是后花园靠近院墙的一个角落，人们常常忽视这个地方，高大的院墙挡住
了外界的一切，但你却可以看清后花园里的动静。一条石子铺成的小路直通后院门
口，小路两边种满了花草，可见这里常有人照料。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "north" : __DIR__"backdoor",
   "west" : __DIR__"southpond",
   ]));

   set("objects", ([
      __DIR__"npc/afu": 1,
   ]) );
   set("outdoors", "qingping");
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
   replace_program(ROOM);

}

