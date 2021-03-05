#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",CYN "青室"NOR);
  set("long",@LONG
对面墙上一大幅山水画，青山碧水，让你觉得心胸为之一宽。室内都是青色，
青得可爱，青得纯真！
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/cyngirl" : 1,
       ]) );
    set("item_desc",([
    	"picture": "这幅画似乎可以掀开(open)。\n",
        "画": "这幅画似乎可以掀开(open)。\n",
        "山水画": "这幅画似乎可以掀开(open)。\n",
        "hua": "这幅画似乎可以掀开(open)。\n",

    ]) );
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 }
void init()
{
	add_action("do_open","open");
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
        if( arg == "picture" || arg == "画" || arg == "hua" || arg == "山水画")
        {
        me = this_player();
        message_vision("$N轻轻掀起墙上的山水画，露出了后面的暗门。\n", me);
        tell_object(me,"你不禁暗自窃喜：“老套子了，我一下就找到了。”\n");
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"gu5");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;                     }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"山水画荡了回来，又遮住了暗门。\n",
                this_object() );
                delete("exits/south");
}
