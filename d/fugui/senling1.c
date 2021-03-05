inherit ROOM;

void create()
{
	set("short", "松林");

	set("long", @LONG
这里是富贵山庄后园一片密密的松木林，四周一片寂静。松针落的遍地都是，
几乎把整个小路铺成了条软软的松毯，不知名的野兔偷偷逃过，小路旁就是条静静
流淌的小溪，溪水上漂浮着松针黄叶，荡开枝叶，依稀可看到溪水碧绿如镜，清澈
见底。
LONG);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"east":__DIR__"grass1",
		"northwest":__DIR__"senling2",
	]) );
	
	set("coor/x",-10);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
