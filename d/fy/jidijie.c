inherit ROOM;
void create()
{
    set("short", "及第街");
    set("long", @LONG
街上石板已经被踩得高高低低，多少寒窗苦读的学子从这里踏上他们的青云之
路，长街末的墙头是人头攒动的放榜处，嬉笑怒骂，或疯或颠，这静静的皇榜阅尽
了多少人间悲喜。北面就是读书人的圣地贡院；西面是警世书局；南面是青云诗社。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"nwind1",
	"north" : __DIR__"examp",
	"west" : __DIR__"jssju",
	"south" : __DIR__"shishe",
      ]));
    set("objects", ([
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}
