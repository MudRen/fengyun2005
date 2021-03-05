
inherit ROOM;

void create()
{
        set("short", "山庄前院");
        set("long", @LONG
这里的装饰古朴而幽雅。院子的四周稀疏的种着黄色的枚瑰，乍看似乎没有什
么次序，却令人感到说不出的自然。院子的左角载着课精心修剪过的梅花树，每当
天寒地冻之时，雪白而又透着粉红的梅花竞相争妍。
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"gate",
  		"north" : __DIR__"bamboo_hall",
]));
        set("outdoors", "resort");

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

