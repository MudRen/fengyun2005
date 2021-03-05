inherit ROOM;

void create()
{
//	object		con,item;

	set("short", "练武厅");
	set("long", @LONG
正面墙上挂著武当开山祖师－张三丰的画像。画像下一张供台上，放著一只铜
炉，几只缓缓冒著青烟的供香插在其中。左右两面墙上挂著太极拳的练功图。图下
则是兵器架，上有各式兵刃，但以剑为多。几个武当道人正在练功。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"wudang3",
	]));
        set("objects", ([
                __DIR__"npc/taoist" : 2,
                __DIR__"obj/wshelf" : 1,
                BOOKS"skill/taiji_50" : 1,
                
        ]));
	set("coor/x",50);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}


void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("weapon shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword");
                item->move(con);
  	}
}