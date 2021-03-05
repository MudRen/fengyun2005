// Room: zhangstall.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "老张记面摊");

	set("long", @LONG
老张头的面摊就在石板路拐角处，很小，但很干净，菜里绝不会有苍蝇。附近
的乡民们大都自个儿烧饭，因此老张头的生意也不算很好，每天雷打不动的老客那
就得数附近县城里三班捕快的老大杨铮和他的一班兄弟们。
LONG);

	set("type","street");
	set("exits",([
    "northwest":__DIR__"stoneroad3",
	]) );

        set("objects", ([
                __DIR__"npc/oldzhang": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",5);
	set("coor/y",-10);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
