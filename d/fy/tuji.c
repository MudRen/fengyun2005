inherit ROOM;
void create()
{
    set("short", "屠记肉铺");
    set("long", @LONG
脏稀稀的木板上放着几块颜色灰暗，不堪入目的生肉。一堆绿头苍蝇忙忙碌碌
的飞起飞落。几个生了锈的铁勾上挂着半风干了的羊头，猪头，和牛头。柜台的左
角儿放着几个木匣，匣中放着些煮熟了的杂碎和排骨。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"lssquare2",
      ]));
    set("objects", ([
	__DIR__"npc/butcher" : 1,
      ]) );

    set("coor/x",160);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
