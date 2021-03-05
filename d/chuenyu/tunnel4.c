
inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
这里黑黑暗暗，几乎伸手不见五指。唯一的光亮来自墙上忽明忽暗的松油灯。
地上和墙上布满了暗红色的血痕，散发出阵阵腥气。不断传来的哀嚎声在死沉的地
牢里回荡，令人毛骨耸然。地牢的天花板上镶着一块石板，从石板的缝隙间射进几
束阳光。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "south" : __DIR__"dungeon",
	]));
        set("item_desc", ([
                "rock": "很沉重的石板，但你似乎可以推动它。\n",
		"石板":"很沉重的石板，但你似乎可以推动它。\n"
        ]) );

	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",5);
	setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
	object room;
        if( (int)query("trigger")==13 && !query("exits/up") ) {
                message("vision", "石板终于被推的斜立起来，露出一个向上的缝隙。\n",this_object() );
                set("exits/up", __DIR__"east_castle");
        	if( room = find_object(__DIR__"east_castle") ) {
                	message("vision","地下的石板被推的斜立起来，露出一条窄缝。\n",room );
                       room->set("exits/down", __FILE__);
        	}
                delete("trigger");
                call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;
        if( !query("exits/up") ) return;
        
        message("vision", "石板“轰”的一声又倒了下来，将向上的通道盖住了。\n", this_object());
        if( room = find_object(__DIR__"east_castle") ) {
                message("vision", "石板“轰”的一声又倒了下去，将向下的通道盖住了。\n",room );
                room->delete("exits/down");
        }
	delete("exits/up");
	delete("trigger");
}


int do_push(string arg)
{
        string dir;

        if( !arg || arg=="" ) 
        {
                write("你要推什么？\n");
                return 1;
        }

        if( arg=="rock" || arg == "石板") {
		if (query("exits/up")) {
			tell_object(this_player(),"石板已经被推开了。\n");
			return 1;
		}
		add("trigger", 1);
                write("你试著往上用力推动石板，石板变得越来越松动了....\n");
		check_trigger();
                return 1;
                }
}


void reset()
{
        ::reset();
        delete("trigger");
}
 
