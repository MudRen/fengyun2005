inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "地室");
        set("long", @LONG
若不是有人指引你，就算有一万人来找，也绝对找不到这地方。这实在是个很
奇妙的地方，里面非但有酒，居然还有张很干净的床，很精致的妆台，妆台上居然
还摆着鲜花，摆酒的桌子上，居然还有几样很精致的小菜。不过，如果你无意间看
一眼东面墙上的黑幔，你就再也不会有兴致欣赏这一切了，因为那黑幔里透出无穷
无尽的憎恨和悲哀。
LONG
        );
        set("exits", ([ 
		"up" : __DIR__"grassland7",
	]));
        set("item_desc", ([
        	"curtain":	"漆黑的布幔遮在东墙上，你能感到后面透出无穷无尽的憎恨和悲哀。\n",
        	"黑幔":		"漆黑的布幔遮在东墙上，你能感到后面透出无穷无尽的憎恨和悲哀。\n",
        ]) );
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",120);
        set("coor/y",90);
        set("coor/z",-10);
	set("map","zbwest");
	setup();

}

void init() {
        add_action("do_open", "open");
        if (this_player()->query("marks/wanma/寻地洞")) 
        	this_player()->set_temp("marks/wanma/进黑屋",1);
}

int do_open(string arg)	{
        object obj;
        object me;
        if(!arg || arg=="" || (arg!= "curtain" && arg != "黑幔") ) {
                return notify_fail("你要打开什么？\n");
        }else {
		me = this_player();
        	message_vision("$N拉起墙上的黑幔，一扇暗门通向东面的黑屋。\n", me);
        	if( !query("exits/east") ) {
        		set("exits/east", __DIR__"hole2");
        		call_out("close_path", 1);
        	}
        }
        return 1;
}


void close_path() {
        if( !query("exits/east") ) return;
        message("vision","黑幔垂了下来，又遮住了暗门。\n",this_object() );
        delete("exits/east");
}


int valid_leave(object me, string arg){
	object blade;
	if (arg!="east")	return 1;
	if (me->query_temp("marks/wanma/进黑屋")) return 1;
	
	tell_object(me,BLU"一股无形的压力阻住了你的去路。\n"NOR);
	if (me->query("marks/wanma/杀傅红雪") && blade=present("black blade",me)) {
		message_vision("$N高声叫道：“在下是为了傅红雪傅公子，有急事求见。”\n");
		tell_object(me,CYN"屋内的人似乎犹豫了一下，你身前的压力减轻了。\n"NOR);
		me->set_temp("marks/wanma/进黑屋",1);
	}
	return notify_fail("");
}