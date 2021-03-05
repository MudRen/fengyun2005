
inherit ROOM;

void create()
{
	object		con, item;

	set("short", "农家");
	set("long", @LONG
红砖砌成的房子，屋内左边靠墙是一张大炕，可容一家人休息。中间一张吃饭
桌，上面摆著几盘菜。一个老妇人正在后面的厨房里忙碌。不时地阵阵饭香从后飘
来，使你想到，这些年来，你在江湖上争名夺利，已很久没好好地吃一顿家人做的
饭菜了。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzroad2",
		"east" : __DIR__"xzh1k",
	]));
	set("objects", ([
		__DIR__"obj/table": 1,
	]));
	set("coor/x",10);
	set("coor/y",80);
	set("coor/z",-50);
	setup();

}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 6) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/rice");
                item->move(con);
                item = new(__DIR__"obj/rice");
                item->move(con);
                item = new(__DIR__"obj/chopstick");
                item->move(con);
                item = new(__DIR__"obj/chopstick");
                item->move(con);
                item = new(__DIR__"obj/vege");
                item->move(con);
                item = new(__DIR__"obj/vege");
                item->move(con);
	}
}
