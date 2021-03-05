inherit ROOM;
void create()
{
    set("short", "浸龙堂");
    set("long", @LONG
地板是上好的檀香木，光滑而略带潮湿。左手边是一个柜台，后面有个架子，
上面挂满了白毛巾。几个如花似玉的小丫环正在忙碌，望向窗外，一个巨大的青铜
缸架在烈火上，丫环们正在慢慢的加入清泉水。
LONG
    );
    set("exits", ([
	"east" : __DIR__"huanyun2",
	"north" : __DIR__"jlonglang1",
      ]));
    set("objects", ([
	__DIR__"npc/showergirl": 2,
      ]) );
    set("coor/x",-80);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}
