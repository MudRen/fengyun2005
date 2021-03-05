inherit ROOM;

void create()
{
	set("short", "萧十一郎的家");

	set("long", @LONG
这间小木屋依山而建，便是大盗萧十一郎的家了。除了一张木床外，屋子里几
乎什么都没有，显得说不出的冷清，说不出的空虚，每次萧十一郎回到这里来，开
始时也许会觉得很宁静。但到了后来，他的心反而更乱了。没有人的地方，岂不也
是孤独的地方？                                
LONG);

	set("type","street");
	set("exits",([
        "out":__DIR__"mudedge",
	]) );
       set("indoors", "wolfmount");
        set("objects", ([
        __DIR__"npc/xiao" : 1,
                        ]) );
	set("coor/x",110);
	set("coor/y",20);
	set("coor/z",-60);

	setup();
	replace_program(ROOM);
}
