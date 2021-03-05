inherit ROOM;
void create()
{
        set("short", "竹林");
        set("long", @LONG
这里是一片竹林。到处都是丈高的竹子，遮住了头顶的天空，密不透光。
空中响着一种奇怪的声音，让你心神不宁。走着走着，你已经看不到来时的
方向了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"bomboo2",
	"east"  : __DIR__"bomboo2",
	"north" : __DIR__"bomboo2",
	"west"  : __DIR__"bomboo2",
]));
        set("item_desc", ([
                "bamboo": "一片竹林似乎可以推开（push）。\n",
                "竹林": "一片竹林似乎可以推开（push）。\n",
       ]) );
        set("outdoors", "fengyun");
	set("coor/x",-40);
	set("coor/y",440);
	set("coor/z",0);

        setup();
}
void init()
{
	add_action("do_push","push");
	add_action("do_pick","pick");
	add_action("do_listen","listen");
}

int do_listen(){
	tell_object(this_player(),"你侧耳聆听，似乎有刀剑互击，兵刃破空之声。\n");
	if ( QUESTS_D->verify_quest(this_player(),"竹林侠隐"))
		QUESTS_D->special_reward(this_player(),"竹林侠隐");
	return 1;
}

int do_pick(string arg)
{
	object bamboo;
	if ( !arg && arg != "bamboo" && arg != "竹子" )
		return notify_fail("你要折什么？\n");
	if((int) query("picked") <= 3)
	{
		write("你折了一根青青的竹子，小心的放在怀里。\n");
		bamboo = new("/d/taoyuan/obj/bamboo");
		bamboo->move(this_player());
		add("picked",1);
		return 1;
	}
	else
        write("竹子已经被人折光了！！\n");
        return 1;
}

int do_push(string arg)
{
    object me;
    if(!arg || arg==""){
        write("你要推什么？\n");
        return 1;
    }
    if( arg == "bamboo" || arg == "竹林" || arg == "竹子"){
	    me = this_player();
	    me->perform_busy(1);
	    message_vision("$N用力的推开竹子。\n", me);
	        
	    if(me->query("marks/梅山民") && !query("exits/northeast")) {
	    	message_vision("$N立定身形向四周察看了一番，发现东北方向的竹子似乎有人经常拨开。\n", me);
	    	set("exits/northeast", __DIR__"meilin");
	    	call_out("close_path", 5);
	    } else if( !query("exits/southwest") ) {
		    message_vision("竹子向后倒去，露出一条通向西南方向的小道。。\n", me);
		    set("exits/southwest", __DIR__"bomboo");
		    call_out("close_path", 10);
    	}
    	return 1;
    } else {
        write("你不可以推"+arg+"\n");
        return 1;
    }
}


void close_path()
{
    if( query("exits/southwest") ) {
	    message("vision", "竹子弹了回来，挡住了去路。\n", this_object() );
    	delete("exits/southwest");
	} else if( query("exits/northeast") ) {
		message("vision", "竹子弹了回来，挡住了去路。\n", this_object() );
		delete("exits/northeast");
	}
}

