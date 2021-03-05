inherit ROOM;
void create()
{
        set("short", "张家铁铺");
        set("long", @LONG
风云老少都喜欢在这里打造称手的铁器，从火炉中冒出的火光将墙
壁映得通红，屋子的角落里堆满了各式铁器的完成品或未完成品，像是锄
头、铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。
门口有一个大木牌（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ecloud3",
]));

        set("objects", ([
                "/d/fy/npc/smith": 1 ]) );
        set("coor/x",30);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}