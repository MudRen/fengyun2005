inherit ROOM;
void create()
{
        set("short", "城隍庙");
        set("long", @LONG
阴暗潮湿，破旧不堪，每当狂风吹过，整座庙都在摇晃，似乎马上就会倒塌下来。
一支残烛在风中摇曳，忽明忽暗，鬼气森森。整个庙里布满灰尘。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"nwind5", 
]));
        set("coor/x",5);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
}


