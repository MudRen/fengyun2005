
inherit ROOM;

void create()
{
        set("short", "青砖甬道");
        set("long", @LONG
两侧是一人多高的白布帐幔，大青砖铺成的甬道笔直的通向前方，甬道旁种植
着一些奇花异草，有的开得正芬芳，再往前甬道微微拐了一个弯，使你看不到前面
的景物，只见转弯之处迷迷蒙蒙浮着层水汽。
LONG
        );
    set("exits", ([ 
  		"southeast" : __DIR__"yuquan",
		"north" : __DIR__"yupond",
	]));
   
    set("outdoors", "huashan");
	set("coor/x",-10);
	set("coor/y",15);
	set("coor/z",-10);
	set("objects", ([
                __DIR__"npc/jin" : 1,
      ]) );
	setup();
}
void open_path()
{
	if( !query("exits/east") ) 
	{
		set("exits/east", __DIR__"hpath1");
        call_out("close_path", 5);
	}
}
void close_path()
{
	if( !query("exits/east") ) return;
	delete("exits/east");
}
