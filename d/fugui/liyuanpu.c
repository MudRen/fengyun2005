inherit ROOM;

void create()
{
	set("short", "利源当铺");

	set("long", @LONG
这屋子便是远近闻名的利源当铺，也和城里别的人家一样，建筑得朴实简陋，
窄而厚的门，小而高的窗子，昏黄的窗纸，昏黄的灯光。一个身影勾偻，白发苍苍
的老头子手里提着桶脏水正准备往外就泼。
LONG);
	
	set("type","house");
	set("exits",([
		"west":__DIR__"xiaojie3",
	]) );
    	set("objects", ([
        	__DIR__"npc/huo" : 1,
        ]) );

	set("coor/x",30);
	set("coor/y",90);
	set("coor/z",0);
	setup();
}
