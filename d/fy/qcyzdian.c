inherit ROOM;
void create()
{
    set("short", "倾城胭脂店");
    set("long", @LONG
这里陈列着各式各样的胭脂，有从京都运来的，也有本地产的。胭脂鲜红似血,
香气扑鼻。每当朝阳初升，阳光照入店内，映在胭脂上，给人一种耀眼的亮红。除
了胭脂这里还卖刨花油，花粉袋。店老板听说就是五十年来江湖中有名的易容高手。
LONG
    );
    set("exits", ([
	"east" : __DIR__"swind31",
      ]));
    set("objects", ([
	__DIR__"npc/makeupseller": 1,
	__DIR__"npc/younggirl": 2,
	__DIR__"npc/youngman": 2,
      ]) );
    set("coor/x",-20);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
