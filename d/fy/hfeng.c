
inherit ROOM;

void create()
{
    set("short", "浣凰堂");
    set("long", @LONG
浣凰堂的门面比以前大多了，四面墙上风干的花环散发着醉人的香气。大堂的
中央还是当年那个古色古香的青铜仙鹤，鹤嘴里面飘出袅袅青烟，沁人心脾。大堂
的右边是一个小小的柜台，台子的后面有一个木架，架子上挂满了白毛巾。
LONG
    );
    set("exits", ([
	"east" : __DIR__"huanyun21",
	"south" : __DIR__"hfenglang1",
      ]));
    set("objects", ([
	__DIR__"npc/showerboy": 1,
      ]) );
    set("coor/x",-80);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
