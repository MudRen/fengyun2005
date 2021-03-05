inherit ROOM;
void create()
{
        set("short", "茶亭");
        set("long", @LONG
这是一间简易的茶亭，专门供过往的路人歇脚用。茶亭里摆着两张桌子和几只
凳子。金狮镖局的镖车到了这里往往都要停一停，让走累了的挑夫和镖师喝口水，
但也因为如此，这里也是山西劫匪们最喜欢光顾的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"road2",
	]));
        set("objects", ([
        	__DIR__"npc/xiaofan": 1,
                     ]) );
        set("outdoors", "fengyun");
	set("coor/x",-200);
	set("coor/y",220);
	set("coor/z",0);
        setup();
    
}
