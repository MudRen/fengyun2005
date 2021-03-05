inherit ROOM;

void create()
{
        set("short", "南天街");
        set("long", @LONG
一条灯火通明的长廊，似乎原先本是繁华的街道，两旁是一些寺院民宅，后来
快活王占据这古楼兰的地下王国后，便将大大小小的民宅修葺改建，以供手下酒色
财气四使、急风三十六骑以及众多嫔妃佳人和一干下人居住。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"saintpalace",
		"south" : __DIR__"southstrt",
	]));
        set("indoors", "loulan");

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
