inherit ROOM;

void create()
{
	set("short", "青石小街");

	set("long", @LONG
这里便是吉祥镇了，是座很宁静的小镇，街道略嫌窄了些，而且有点陡斜。两
旁房屋的构造也很平凡。长街很静，只有三两家的窗户里，还燃着暗淡的灯火。西
侧是家钱庄，往东则有条绵延曲折的小路。小街边上一个正值妙龄的女子张罗了个
卖衣服的小摊，羞答答地看着你。
LONG);
	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"shilu1",
		"west":__DIR__"qianzhuang",
		"south":__DIR__"qinshilu",
		"north":__DIR__"xiaojie3",
	]) );
        set("objects", ([
        	__DIR__"npc/clothlady" : 1,
                        ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
