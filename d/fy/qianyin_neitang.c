// inn.c

inherit ROOM;


void create()
{
    set("short", "当铺内堂");
    set("long", @LONG
走进当铺内堂，墙上挂着三大财神画像，一般人家只供一个财神，唯独当铺供
的是三个，当铺老板的贪心可略见一二了。画像下边一侧两张桌子一个是相当于现
在的出纳坐，另一个是帐房先生的位子。
LONG
    );

    set("exits", ([
	"east"      : __DIR__"qianyin",
      ]) );
    set("objects", ([
//	__DIR__"npc/hockowner" : 1,
        __DIR__"npc/tatoo": 1,
//add by ldb  因为玩的人少，当铺这里加个活动NPC走动，要长时间没人来玩家卖的东西会自动清光。 
      ]) );


    set("coor/x",-110);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
//    replace_program(ROOM);
    setup();
}
