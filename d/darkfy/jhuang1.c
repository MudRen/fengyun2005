inherit ROOM;
void create()
{
        set("short", "绿衣室");
        set("long", @LONG
绿衣警卫专门负责美刀帮总舵的安全。凡是来人，都要经过他们的检察。这里是他
们轮班休息的所在。屋中有几张小床，几张小几。每张床头都有小钩，警卫们都把兵
器挂在钩上，一伸手，他们就可以最快的速度拔出自己的兵器。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jting",
  "south" : __DIR__"jbang",
]));
        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );

        set("coor/x",-20);
        set("coor/y",-35);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
