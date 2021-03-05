
inherit ROOM;
void create()
{
        set("short", "小街");
        set("long", @LONG
小街两旁是住家，很普通的那种平房，西北最普通，最常见的砖土四合院，住
的也是很普通的人家。多数是靠手艺吃饭的，有开小杂货铺的，理发的，打铁的，
伐木的，也有的是常年奔波于塞外和中原的生意人。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house2",
		"north": __DIR__"mroad4",
		"south": __DIR__"mroad5",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
