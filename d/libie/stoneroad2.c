// Room: stoneroad2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "石板路");

	set("long", @LONG
这只是一个无名的小县城，城中没几户人家，只有一条石板路可供路人来往，
石板上青苔厚绿，一不小心便会摔个跟头。路的一边是家小县城里老字号的“悦
来客栈”，另一边往里走则是条既破且旧的暗巷。	
LONG);

	//{{ --- by MapMaker
	set("type","street");
	set("exits",([
	"east":__DIR__"stoneroad",
	"south":__DIR__"yuelai",
	"north":__DIR__"darklane1",
	]) );
	//}}
		    set("objects", ([
        __DIR__"npc/oldman" : 1,
    ]) );
        set("outdoors", "libie");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);


	setup();
	replace_program(ROOM);
}
