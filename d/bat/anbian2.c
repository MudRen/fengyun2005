
inherit ROOM;
void create()
{
    set("short", "海岸边");
    set("long", @LONG
你仿佛步入了仙境，怀疑这里是否还是人间，依稀是传说中西方灵河岸边，一
块雪白的石头上生着一株晶莹剔透、摇曳多姿的小草，石上刻着三字－－－三生石。
LONG
	);
    
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"anbian1",
        ]));
    set("objects", ([
        __DIR__"obj/boat" :1,
        ]));
    set("outdoors", "bat");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",30);
    setup();
    replace_program(ROOM);
}



