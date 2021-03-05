//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "天街");
    set("long", @LONG
过三仙碑，一条长街向两边延伸，隐没于亭殿之中。天街的两旁由连檐通
脊的长廊甚是整齐工直。你心中径自生出一股严肃庄穆的气氛来，禁不住的收
敛了笑意。路行至尽头，隐隐传来婉转曼妙的歌舞之声。
LONG
    );
    set("exits",
      ([
	"west" : __DIR__"3xian",
	"north": __DIR__"yiye",
	"enter" : __DIR__"wangxian", 
	"south": __DIR__"treasure",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
