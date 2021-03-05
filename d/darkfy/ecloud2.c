inherit ROOM;
void create()
{
        set("short", "东云大路");
        set("long", @LONG
这里是风云城中三教九流，龙蛇混集之所。不管你是达官贵人，还是贩夫走卒，
只要你身上有两钱儿，在这里就会受到热情的招呼。任何你不知道的事，在这里打
听一下，都可以知道个八九不离十。整条街上有卖菜的，卖肉的，卖玩具的，卖艺
的，卖药的...，应有尽有。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud3",
  "west" : __DIR__"ecloud1",
  "north": __DIR__"bupu",
  "south": __DIR__"jijian",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
			]) );

        set("outdoors", "fengyun");
        set("coor/x",20);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
