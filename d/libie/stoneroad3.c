// Room: stoneroad.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "石板路");

	set("long", @LONG
小县城中便只有一条石板路可供路人来往，路的两边零零星星有几户人家，石
板上青苔厚绿，一不小心便会摔个跟头。远处是一片梅林，空气中飘荡着若有若无
的梅子初熟的味道。	
LONG);

	set("type","road");
	set("exits",([
	"south":"/d/fycycle/road5",
    "west":__DIR__"stoneroad",
    "east":__DIR__"stoneroad4",
	"southeast":__DIR__"zhangstall",
	]) );
	//}}

        set("outdoors", "libie");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
