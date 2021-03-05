inherit ROOM;

void create()
{
	set("short", "乱葬冈");

	set("long", @LONG
这里是附近百姓们谈之色变的乱葬冈，齐人高的野草在阵阵阴风中摇摆不定，
周围密密麻麻地堆了好几十个坟头。但看上去都很久没有人祭祀，墓碑东一块，西
一块倒在地上，一副破败不堪的景象。
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"northwest":__DIR__"tomb4",
		"southwest":__DIR__"tomb3",
		"east":__DIR__"tomb",
	]) );
	set("objects", ([
                __DIR__"obj/fakecaoren" : 1,
         ]) );
	set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_push", "pushaside");
}

int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要拨开什么？\n");
                return 1;
        }
        if( arg == "稻草人" || arg == "ren" || arg == "草人" )
        {
        	me = this_player();
        	message_vision("$N拨了拨路边的稻草人，稻草人有如活了一般，左右摇摆。\n", me);
        	return 1;
 	}
 	else
        {
                write("你不可以拨开"+arg+"\n");
                return 1;
        }
}