#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乱葬冈");

	set("long", @LONG
这里是附近百姓们谈之色变的乱葬冈，齐人高的野草在阵阵阴风中摇摆不定，
周围密密麻麻地堆了好几十个坟头。但看上去都很久没有人祭祀，墓碑东一块，西
一块倒在地上，一副破败不堪的景象。厚厚的[37m野草[32m在风中摇摆，淹没了脚下的路。
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"milin2",
		"north":__DIR__"tomb1",
	]) );

	set("item_desc", ([
                "grass": "野草在风中左右摇摆，挡住了去路，但你似乎可以拨开(pushaside)它。\n",
                "野草": "野草在风中左右摇摆，挡住了去路，但你似乎可以拨开(pushaside)它。\n"
        ]) );
        set("objects", ([
                __DIR__"obj/fakecaoren" : 1,
         ]) );
	set("coor/x",-30);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{	object ob;
	string outexit;
	add_action("do_push", "pushaside");
	if( interactive( ob = this_player()))
	{
		if(query("exits/east")) delete("exits/east");
		outexit = __DIR__"milin"+(string)(1+ random(25))+ ".c";	
		set("exits/east", outexit);
	}
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
        if( arg == "野草" || arg == "grass" || arg == "草" )
        {
        	me = this_player();
        	message_vision("$N拨开路边的野草，发现了一条向西的路。\n", me);
 	if( !query("exits/west") ) 
 	{
		set("exits/west", __DIR__"tomb2");
		call_out("close_path", 5);
	}
        return 1;
        }
        else
        {
                write("你不可以拨开"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/west") ) 
        	return;
        message("vision",
"一阵风吹过，野草有如活了一般，左右摇摆，又挡住了去路。\n",this_object() );
	delete("exits/west");
}
