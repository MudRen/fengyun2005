
inherit ROOM;

void create()
{
        set("short", "富家大院");
        set("long", @LONG
住在这里的据说是个富豪，他并没有什么固定的生意，只要是赚钱的生意，他
都插上一脚，集市里的各种生意，每天若能赚过十两银子，就有二两是他的。传说
他本来也是个穷光蛋，到沙漠里转了五年出来，就成了沙漠上最精明的商人，最大
的富翁。
LONG
        );
        set("exits", ([ 
  		"east": __DIR__"fair2",
  		"enter": __DIR__"house2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );
	set("coor/x",-1032);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

