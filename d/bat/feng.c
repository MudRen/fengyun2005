inherit ROOM;
void create()
{
        set("short", "有凤来仪");
        set("long", @LONG
这是一间卧室，虽然并不富丽堂皇，各样东西却都十分精致得体，靠南是一面
屏风，靠西边有一张凤尾琴。东面墙上挂着一副对联：
[1;36m
                        弦歌知雅意，
                        杯酒谢良朋。

[2;37;0m
LONG
        );
		set("exits", ([ 
  			"west" : __DIR__"huashi",
		]));
        set("objects", ([
       		__DIR__"npc/yuan": 1,
        ]) );
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		set("NONPC",1);
		setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
//      object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "屏风" || arg == "ping feng" || arg == "pingfeng")
        {
        me = this_player();
        message_vision("$N信手按在屏风上，屏风微微一动，过得片刻，屏风
竟然向左移开来，露出一道暗门。 \n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"secret");
        call_out("close_path", 6);
        }
        return 1;
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/south") ) return;
        message("vision","屏风自行移了回来。\n",this_object() );
        delete("exits/south");
}


