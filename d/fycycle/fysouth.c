inherit ROOM;
void create()
{
    set("short", "风云南");
    set("long", @LONG
虽说比不上城里的热闹，比起乡野小镇来这里还是繁华不少，风云城周围的星
罗棋布有许多集市，城里的大富人家经常派人到这里采购新鲜的蔬菜水果，远道而
来的客商也总在这里歇一歇脚。
LONG
    );
    set("exits", ([ 
	"north" : AREA_FY"sgate",
	"east"  : __DIR__"sroad4",
	"west"  : __DIR__"sroad3",
	"south"  : __DIR__"fysroad1",
	//   "south" : AREA_FY"sroad1",

      ]));
    set("objects", ([
	__DIR__"npc/xiaofan" : 1,
	"/d/fy/npc/wind_soldier" : 1,
      ]) );        
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-320);
    set("coor/z",0);

    setup();
}
