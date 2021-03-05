inherit ROOM;
void create()
{
    set("short", "荒凉大道");
    set("long", @LONG
集市再往南，人烟渐稀，这儿远比不上北城外南北大道的热闹，寒风呼啸，尘
土飞扬，湮没了仅有的几条车轱辘印，远方黑沉沉的，是一片无边无际的原始森林。
偶尔会有客商结队而过，据说穿过森林便可以到达出海的港口。
LONG
    );
    set("exits", ([ 
	"north" : __DIR__"fysroad1",
	"south" : AREA_MANGLIN"edge2",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-440);
    set("coor/z",0);
    setup();
}

