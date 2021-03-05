inherit ROOM;

void create()
{
	set("short", "青石小街");

	set("long", @LONG
这是座很宁静的小镇，街道略嫌窄了些，而且有点陡斜。两旁房屋的构造也很
平凡。长街很静，只有三两家的窗户里，还燃着暗淡的灯火。东边是此地独此一家
的酒店，老字号的“奎元馆”，西边则是一家杂货铺。
LONG);
	set("type","street");
	set("outdoors", "fugui");

		set("objects", ([
        __DIR__"npc/amine" : 1,
                        ]) );

	set("exits",([
		"east":__DIR__"kuiyuanguan",
		"west":__DIR__"zuohuopu",
		"south":__DIR__"xiaojie3",
		"north":__DIR__"xiaojie1",
	]) );
	set("coor/x",20);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
