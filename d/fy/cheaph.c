inherit ROOM;
void create()
{
    set("short", "土嫖馆");
    set("long", @LONG
一间简陋的，用泥坯砌起来的低矮小房。东面的墙上有条裂缝，从右上角一直
裂到左边的墙角里。西边有一张和泥屋连为一体的土炕。炕下有灶，炕头挂着厚布
蚊帐，帐上贴纸一张：价格最平，男女老少皆宜，恕不找钱。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"stone1",
      ]));
    set("objects", ([
	__DIR__"npc/chick" : 1,
      ]) );
    set("no_preach",1);
    set("coor/x",260);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
