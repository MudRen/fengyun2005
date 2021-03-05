//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "云间茶坊");
    set("long", @LONG
只在此山中，云深不知处。云间茶坊位于白云城西，平时城中并无多少客人，倒
是近来突然不知是何原因，白云岛汇聚了不少江湖上各门各派的僧道儒侠，殊是热闹。
因此向来清闲的云间茶坊一时间聚满了各式各样的人物，无论高矮胖瘦，文人武夫，
似乎来到白云岛后都变成高雅不俗起来。
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"skystreet3",
      ]));
    set("objects",
      ([        __DIR__"npc/qianqian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-170);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
