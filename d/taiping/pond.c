inherit ROOM;
void create()
{
        set("short", "荷塘");
        set("long", @LONG
周围都是已开始凋残的荷花，荷叶田田，重重叠叠的盖住了整个荷塘。星月照
不到水面，荷塘的四面更植满了树木，再加上高墙三丈，月在高墙之外，整个荷塘
就裹在黑暗中。西侧有一扇铁门，门上的锁已经生锈。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"lroad1",
		"south": __DIR__"grass3",
		"north": __DIR__"grass2",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([  
		"door": "一扇铁门，门上的铜锁已经锈死了，看来没法打开。\n",
		"铁门": "一扇铁门，门上的铜锁已经锈死了，看来没法打开。\n",
	]));
	set("coor/x",60);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
