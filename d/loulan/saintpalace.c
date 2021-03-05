
inherit ROOM;

void create()
{
        set("short", "圣殿");
        set("long", @LONG
故老相传楼兰的王族世代传下一件神奇的宝物，但代代无人能参详出宝物的奥
秘，相传若有人能参出其奥秘，此人便是上天派到楼兰的圣人，能带领楼兰全族走
出困境。因此昔年楼兰人耗举国之人丁财力，兴修了这座圣殿，如今圣殿彷佛如同
昔日般灿烂庄严，玉石壁上彩绘浮雕栩栩如生。大殿上红烛高燃，鲜红的毛毡铺在
白玉石阶上，原本供奉着楼兰圣女的高台上高高放了张金交椅。
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"weststrt",
		"east" : __DIR__"eaststrt",
		"south" : __DIR__"southstrt3",
		"north" : __DIR__"northstrt3",
	]));
        set("objects", ([
                __DIR__"npc/chai" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}