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
	"north" : __DIR__"jting",
	"south" : __DIR__"jbang",
      ]));
    set("objects", ([
	__DIR__"npc/huangyi2" : 1,
	__DIR__"npc/huangyi" : 2,
      ]) );

    set("coor/x",-180);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
