// searoad.c
inherit ROOM;
void create()
{
        set("short", "礁石");
        set("long", @LONG
海边山岩，下面急流澎湃，海浪汹涌，重列着千百块怪兽般的礁石，海边山岩
亦是怪石嵯峨，峥嵘险恶。礁石间恶浪汹涌澎湃，雪白的浪花，飞激四溅。
LONG
        );
		set("item_desc",([
			"rock": "一处尖锐的岩石，似乎可以扳动。(move)\n",
			"礁石" :"一处尖锐的岩石，似乎可以扳动。(move)\n",
		]) );
        set("exits", ([ 
	  	"west": __DIR__"rock0",
  		
	]));
        set("outdoors", "tieflag");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{

    object me;
    if(!arg || arg=="")
    {
    	write("你要扳动什么？\n");
    	return 1;
    }
    if( arg == "rock" || arg == "礁石")
        {
        me = this_player();
        message_vision("$N扳了扳礁石，礁石缓缓滑了开去。\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"hole");
        call_out("close_path", 5);
        }
        return 1;

        }
        else
		{
			write("你要扳动什么？\n");
			return 1;
		}
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"礁石移了回来，遮住了向下的洞口。\n",
                this_object() );
                delete("exits/down");
}
