inherit ROOM;
void create()
{
        set("short", "棉花坊");
        set("long", @LONG
每当天气渐冷，风云老少都会到这儿来将自己的冬衫，
冬被弹一弹，这里的老板娘更善长补衣服，补出来的衣服
又牢固而且不难看。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud4",
]));
        set("objects", ([
        "/d/fy/npc/mianhua" : 1,
                        ]) );

        set("coor/x",40);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
