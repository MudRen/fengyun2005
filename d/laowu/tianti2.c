// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "迷雾天梯");
        set("long", @LONG
一路走来，仔细观察，两边草丛之中居然有许多森森白骨，更有断刃残剑，显
然都是些武林中人，只是为何倒毙这里，令人难以理解。一道精巧的青石拱门横跨
路上，上面横书＂一入此门，再世为人＂，整个拱门显得十分诡异，你不由得心惊
胆颤。
LONG
        );
   	set("exits", ([ 
      		"east" : __DIR__"valley",
      		"southdown" : __DIR__"tianti1",
   	]));
   	set("objects", ([
      		__DIR__"obj/grass": 1,
   	]) );
	set("outdoors","laowui");
	set("coor/x",160);
	set("coor/y",190);
	set("coor/z",20);
	setup();

}

void init(){
	add_action("do_search","search");
}


int do_search(){
	object item, me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	message_vision("$N俯下身去在乱草丛中摸索起来。\n",me);
	if (me->query("maze/闯金钱得无间") && !me->query("maze/得嵩阳铁剑") && !random(10)) {
		tell_object(me,"你觉得手底一沉，摸到了一件长长的物事。\n");
		item = new(__DIR__"obj/sword");
      		item->move(this_object());
      		me->set("maze/得嵩阳铁剑",1);	// Let the mark on player to take care of it.
      	} else
      		tell_object(me,"你什么也没找到。\n");
      	me->start_busy(1);
      	return 1;
}
	
