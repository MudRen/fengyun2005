inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "镖局账房");
    set("long", @LONG
这里是金狮镖局出入镖银的账房，整间屋子是由坚硬的花岗石砌成的。连唯一
的一个小窗上都镶满拇指粗细的钢条。屋角有小床。这里由总镖头最亲信的人日夜
把守。不但如此，房中还有黄铜警铃，铃声一响，镖局伙计们就会蜂拥而至。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"ghall",
      ]));
    set("objects", ([
	__DIR__"npc/xiansheng" : 1,
      ]) );
    set("item_desc", ([
		"bed": "这个小床似乎可以推开(push)。\n",
		"床": "这个小床似乎可以推开(push)。\n",
		"小床": "这个小床似乎可以推开(push)。\n",
		"bell" : "你可以试着摇摇(ring)。\n",
		"铃" : "你可以试着摇摇(ring)。\n",
		"警铃" : "你可以试着摇摇(ring)。\n",
		"黄铜警铃" : "你可以试着摇摇(ring)。\n",
      ]) );
    set("coor/x",180);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fyeast");

    setup();
    create_door("south", "door","铁门", "north", DOOR_CLOSED);

}

void init()
{
    add_action("do_ring", "ring"); 
    add_action("do_push", "push");
}

int do_ring(string arg)
{
    int i;
    object ob;
    if ( !arg || (arg != "bell" && arg != "黄铜警铃" && arg != "警铃" && arg != "铃"))
    {
		return notify_fail("你要摇什么？\n");
    }	
    message_vision("$N试着摇了摇黄铜警铃．．．\n", this_player());
    if( !(int) query("notyet"))
	for(i;i<=random(3)+1;i++)
	{
	    ob = new(__DIR__"npc/resting_biao");
	    if(ob) ob->move(this_object());
	    message_vision("$N冲了进来．．．\n", ob);
	    ob->kill_ob(this_player());
	    set("notyet",1);
	}
    return 1;
}

int do_push(string arg)
{
    object ob;
    object sect;
    if ( !arg || ( arg != "bed" && arg != "小床" && arg != "床"))
	return notify_fail("你要推什么？\n");

    if( ob = present("xian sheng", this_object()))
    {
		message_vision("$N用很一种奇怪的眼神瞄着$n。\n", ob, this_player());
		return 1;
    }
    
    if( !query("exits/down") ) {
		message_vision("$N把小床推开发现了一条密道．\n", this_player());	
		set("exits/down", __DIR__"secret_room");
    }
    else
    {
		message_vision("$N把小床推过来掩盖住密道．\n", this_player());
		delete("exits/down");
    }
    return 1;
}
