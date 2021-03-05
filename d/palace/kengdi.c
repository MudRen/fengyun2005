inherit ROOM;

void create()
{
        set("short", "坑底");
        set("long", @LONG
这是一个深坑的底部。在这里风声凄历，迷雾更浓。抬头仰望，不见天日。四
下鬼影重重，也不知是真是假。转目四望，但见坑中满是被石蛇缠住的石人，哪有
活人的人影。忽听身旁隐约有人喘息的声音，你不禁毛骨悚然。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"obj/eren" : 1,
                        ]) );


	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_open", "touch");
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
        if( arg == "statue" || arg == "恶人像" || arg == "被石蛇缠住的恶人像"
        	|| arg == "eren" )
        {
        me = this_player();
        message_vision("$N俯身走了两步，伸手扳了扳地上的石像．
＂呀＂地一声，深坑边的石壁上，竟裂开了一重门户。\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"secretpath0");

        REWARD_D->riddle_done( me, "入帝王谷", 10, 1);
        
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你伸手扳了扳"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"石壁上的门户又无声无息的合了起来．\n",
                this_object() );
                delete("exits/east");
}
