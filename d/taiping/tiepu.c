// seaside.c
inherit ROOM;
void create()
{
        set("short", "甘家铁铺");
        set("long", @LONG
那是间小小的铁铺，墙壁已被火熏黑。一个小孩子正在拉着风槽。炉火熊熊地
飞扬，站在那前面的一个老头儿似乎已被烤干。他赤裸着上身，肋骨根根可数，那
张脸亦是干尸一样，灰白的须发卷卷曲曲，也不知是天生如此，还是因为经年累月
伴着火炉，被火烘成这样。他一只手拿着铁锤，另一只手拿着火钳，正在打着一柄
菜刀。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"mroad4",
	]));
	set("objects", ([
        	__DIR__"npc/ganlaotou" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
