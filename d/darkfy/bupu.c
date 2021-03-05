inherit ROOM;
void create()
{
        set("short", "风云布铺");
        set("long", @LONG
布铺里摆满了绫罗绸缎，这里专门订作，裁剪，改装各种鞋，帽，
衫．这里做的衣服不但款式新颖，而且经久耐用．风云老少们穿的大
部份都是这里出的．门口有一个大木牌（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));
        set("objects", ([
        "/d/fy/npc/" : 1,
			]) );

        set("coor/x",20);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
