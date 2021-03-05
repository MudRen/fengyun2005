inherit ROOM;
void create()
{
        set("short", "城南小路");
        set("long", @LONG
这里人迹稀少，好象很少有人光顾。向西北望，一座大城耸立云霄。南边有一
大片树林，古木参天，阴森森的让你不敢深入。说不定会有什么强盗或者野兽冒出
来呢，你不禁加快了脚步。前方隐约好象有行人说话的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
	  "west" : __DIR__"fysouth",
	  "northeast": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
	set("coor/x",100);
	set("coor/y",-320);
	set("coor/z",0);

	setup();
}

