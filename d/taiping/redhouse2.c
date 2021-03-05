inherit ROOM;
void create()
{
        set("short", "东耳房");
        set("long", @LONG
这间屋子却与周围的不同，中间客座上面，挂一幅名人山水，香几上博山古铜
炉，烧著龙涎香饼，两旁书桌，摆设些古玩，壁上贴许多诗稿。八仙桌上放着六碗
时新果子，一架攒盒佳肴美酝。鹦鹉楼的老鸨挖空心思布置了这些，就是为了迎合
不同客人的品味。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/lady1":	1,
        ]));
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
