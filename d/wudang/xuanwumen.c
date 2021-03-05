
inherit ROOM;

void create()
{
	set("short", "玄武门");
	set("long", @LONG
你拾阶而上，缓缓上行。不刻已来到玄岳门。玄岳门代表着道教所信仰的“五
城十二楼”，相传这个地方是等候神仙的场所。又为“十二重楼”穴道，故又寓意
此地是阴阳交界处，为武当山第一道神门，被称为仙界第一关。在武当山有“进了
玄岳门，性命交给神”的说法。意思是说，凡人进了这神门仙界后，是生是死，是
福是祸，就由不得自己了。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"road2",
		"southup" : __DIR__"rock",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
