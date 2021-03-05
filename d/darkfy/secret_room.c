
inherit ROOM;

void create()
{
	object silver;
	set("short", "地下密室");
	set("long", @LONG
这里是一间窄小的密室，你的面前只有一个破旧的小床跟一
些乾草。
LONG
	);

	set("coor/x",20);
	set("coor/y",50);
        set("coor/z",-310);
	setup();

}
