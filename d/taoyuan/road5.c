inherit __DIR__"no_killing_place";
void create()
{
    set("short", "石板路尽头");
    set("long", @LONG
青青石板路到了这里已经慢慢被青草所覆盖，再往前似乎没有了路．脚下是柔
软的青草，四周是茂密的丛林，耳边是啾啾的鸟鸣声伴随着流水声。透过眼前的丛
林向西，你可以看到一片碧绿色的草地。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"riverbank",
        "west" : __DIR__"road4",
        "south" : __DIR__ "lawn",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}
