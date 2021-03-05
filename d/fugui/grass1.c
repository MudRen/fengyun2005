// Room: grass1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "芳草坪");

	set("long", @LONG
这里是一块芳草坪，绿草茵茵，蝴蝶漫舞，花香扑鼻，让人感到十分惬意。不
禁令人就想一头躺倒上去，好好的去睡一觉，但这里偶尔也会碰到菜花蛇。往西走
是片小树林，北面则是一间卧室。
LONG
	);

	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"grass2",
		"west":__DIR__"senling1",
		"north":__DIR__"woshi",
		"southeast":__DIR__"shibanlu4",
	]) );
	
        set("objects",([
		__DIR__"npc/baozi" : 1,
		__DIR__"npc/snake" : 1,
	    __DIR__"obj/greengrass" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
