#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这是一间布置非常雅洁的书房，靠墙的紫檀木书桌上摊着副还没完成的美人擎
梅图，靠西墙下的小几上放了一张琴，墙上挂着一副棋盘还有一把剑。靠着北墙而
立的书架上摆满了书。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"meihouse",
	]));

    set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();

}

void init(){
	add_action("do_push","push");
}

int do_push(string arg)
{
	object player;
	player = this_player();
	if (arg != "stone" && arg != "花纹砖")
	{
		return notify_fail("你要推什么？\n");
	}
	if (!player->query("marks/梅山民"))
	{
		return notify_fail("你试着推了推书架旁的一块花纹砖，花纹砖纹丝不动。\n");
	}
	
	if( !query("exits/down") ) 
	{
        message_vision("$N用手按了按那靠着墙而立的书架旁的一块花纹砖，书架便突地一分，露出一处地道，石阶直通着地底。\n",player);
		set("exits/down", __DIR__"groundroom");
        call_out("close_path", 2);
		return 1;
    } else {
		return notify_fail("花纹砖已经被移开了 \n");
	}
    return 1;
}
void close_path()
{
	if( !query("exits/down") ) return;
	message("vision","书架又缓缓的合上了。\n",this_object() );
	delete("exits/down");
}
int valid_leave(object player, string dir)
{
	if ( dir == "down" && (!player->query("marks/梅山民")||player->query("combat_exp")<4000000)){
		return notify_fail("你朝下看了看，想了想，不知下面有什么，还是不要冒险为妙。\n");
	}
	return 1;
}