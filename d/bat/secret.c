inherit ROOM;
void create()
{
        set("short", "密室");
        set("long", @LONG
这是一间非常隐秘的房间，没有窗户，只点着一根蜡烛，烛光黯淡，有如一点
暗夜里的鬼火。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up": __DIR__"tianti1",
  			"north": __DIR__"feng",
		]));

		set("coor/x",0);
		set("coor/y",-10);
		set("coor/z",0);
		setup();
}
