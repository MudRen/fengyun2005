//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "天街");
    set("long", @LONG
过三仙碑，一条长街向两边延伸，隐没于亭殿之中。天街的两旁由连檐通
脊的长廊甚是整齐工直。你心中径自生出一股严肃庄穆的气氛来，禁不住的收
敛了笑意。
LONG
    );
    set("exits",
      ([
	"east" : __DIR__"3xian",
	"south": __DIR__"caiyun", 
	"north": __DIR__"fuyun",
	"west":  __DIR__"lanke",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
