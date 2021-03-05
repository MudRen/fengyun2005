inherit ROOM;
void create()
{
        set("short", "西云大路");
        set("long", @LONG
风云广场在东，知府衙门在西，这里是风云城中风骚文人丛聚之地。据说天下
赫赫有名的小李探花就是在这里中的秀才。南边的考场每年都举行一次选拔考试，
前三名送入京都再试。北面则是探花诗台，是风骚文人们留下他们得意之作的地
方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/xiwei": 1,
                        ]) );


        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}
