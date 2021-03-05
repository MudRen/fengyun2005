inherit ROOM;
void create()
{
        set("short", "赏罚堂");
        set("long", @LONG
金钱帮帮规严明，凡有贪污受贿，无事生非，调戏民女之帮徒，都会在这里受到应
有的制裁。凡有巨功于金钱帮的，都会在这里受到帮主的赏赐和提拔。厅中悬条幅书
道：            赏罚分明
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhuang",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
}



