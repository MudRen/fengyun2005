inherit ROOM;
void create()
{
        set("short", "小街");
        set("long", @LONG
街的两旁种满了枫树。枫是秋天的树木，秋风一吹到，叶就绯红了起来，灿烂
如朝露，正是秋容的胭脂。小街在这胭脂衬托之下，就像个娇丽的佳人。小街西面
是一幢有年头的宅子，东面有一条小巷，巷口用木条胡乱围了个栅栏。街上来来去
去的人不多，每个人的衣着好像都不太陈旧。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house1",
		"east": __DIR__"droad0",
		"southwest": __DIR__"mroad3",
		"northeast": __DIR__"mroad1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
