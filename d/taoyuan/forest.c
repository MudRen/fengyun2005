inherit __DIR__"no_killing_place";
void create()
{
    set("short", "山林边缘");
    set("long", @LONG
细密的茅草渐渐被矮小的灌木所代替，这些不知名的灌木长的十分茂盛，有的
开着淡蓝色的小花，有的结着一串串红色的果实。在这里你隐约还可以辨认出灌木
丛中的小路，再向前灌木又渐渐变成了高大的乔木。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"milin",
        "east" : __DIR__ "lawn",
        ]));

    set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program(__DIR__"no_killing_place");
}
