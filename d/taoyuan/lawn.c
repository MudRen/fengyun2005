inherit __DIR__"no_killing_place";
void create()
{
    set("short", "草地");
    set("long", @LONG
这里是一片开阔草地，四周是茂密的丛林。草地上的草细而软，柔嫩细软的小
草随风拂摆，好似少女额前的秀发。边缘靠近丛林的地方有几只小猫咪在玩耍，一
条蜿蜒的小路穿过丛林往西伸展着，东边生长着一棵葱绿的小树。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"walnuttree",
        "west" : __DIR__"forest",
        "north" : __DIR__ "road5",
        ]));
    set("objects", ([
        __DIR__"npc/cat1" :1,
        __DIR__"npc/cat2" :1,
        ]) );

	set("no_lu_letter",1);
    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",40);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program( __DIR__"no_killing_place");

}
