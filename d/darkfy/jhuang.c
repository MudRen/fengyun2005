inherit ROOM;
void create()
{
        set("short", "黄衣室");
        set("long", @LONG
黄衣警卫专门负责金钱帮总舵的安全。凡是来人，都要经过他们的检察。这里是他
们轮班休息的所在。屋中有几张小床，几张小几。每张床头都有小钩，警卫们都把兵
器挂在钩上，一伸手，他们就可以最快的速度拔出自己的兵刃。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jting",
  "east" : __DIR__"tang1",
  "west" : __DIR__"tang2",
  "north" : __DIR__"tang3",
]));
/*        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );
*/
        set("coor/x",-20);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
