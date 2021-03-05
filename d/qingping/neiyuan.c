inherit ROOM;
void create()
{
        set("short", "内院门");
        set("long", @LONG
一道低低的圆形小门，门后便是家眷门居住的内院了，因为方师侠，白曼纱夫
妇十年前游侠江湖，至今未归，所以后院之中其实只住了他们的独生爱子---方宝
玉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"garden",
  "west" : __DIR__"road2",
   ]));

   set("objects", ([
      __DIR__"npc/hu": 1,
   ]) );
   	set("outdoors","qingping");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
