inherit __DIR__"no_killing_place";
void create()
{
        set("short", "小茶栈");
        set("long", @LONG
也不知道什么时候起，这个小小的茶栈就已经在这儿了，过往的行人实在不多，
只有村民们从地里收工的时候，这里才稍稍显得热闹一些，茶栈却也维持至今。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"road1",
   ]));

   set("objects", ([
      __DIR__"npc/waiter" :1,
      __DIR__"npc/laodie" :1,
      __DIR__"npc/singgirl" :1,
   ]) );

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}
