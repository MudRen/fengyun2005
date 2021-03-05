// seaside.c
inherit ROOM;
void create()
{
        set("short", "小街");
        set("long", @LONG
街的两旁种满了枫树。枫是秋天的树木，秋风一吹到，叶就绯红了起来，灿烂
如朝露，正是秋容的胭脂。小街在这胭脂两旁衬托之下，就像个娇丽的佳人。左侧
的屋檐下挂着个破旧的招牌：“杂货店”，来来去去的人不多，每个人的衣着好像
都不太陈旧。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"zahuo",
		"south": __DIR__"mroad4",
		"northeast": __DIR__"mroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
