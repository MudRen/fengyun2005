inherit ROOM;
void create()
{
    set("short", "黄衣室");
    set("long", @LONG
黄衣警卫专门负责金钱帮总舵的安全。来往的人都要经过他们的仔细盘查。这
里是他们轮班休息的所在。屋中有几张小床，几张小几。每张床头都有小钩，警卫
们都把兵器挂在钩上，一伸手就可以以最快的速度拔出自己的兵刃。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
			"south" : __DIR__"jting",
			"east" : __DIR__"tang1",
			"west" : __DIR__"tang2",
			"north" : __DIR__"tang3",
      ]));
    set("objects", ([
	__DIR__"npc/huangyi" : 2,
	__DIR__"npc/huangyi2" : 1,
      ]) );
	set("NONPC",1);			// to stop dungeon NPCs to come out.
    set("coor/x",-180);
    set("coor/y",100);
    set("coor/z",0);

    set("map","fywest");
    setup();
    replace_program(ROOM);
}
