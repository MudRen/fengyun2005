inherit ROOM;
void create()
{
        set("short", "镖局货仓");
        set("long", @LONG
金狮镖局声誉方日中天，从未失镖。顾主的货物在这里堆积如山。镖局的伙计们
正在手忙脚乱的往镖车上装载货物。虽然每个伙计都已尽力而为，但还是忙不过来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"goldlion",
]));
        set("objects", ([
        __DIR__"npc/" : 3,
                        ]) );

        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
}

