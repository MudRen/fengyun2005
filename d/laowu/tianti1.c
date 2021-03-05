// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "迷雾天梯");
        set("long", @LONG
穿过一片谷地，在雾峰之中，云海之后，居然有一条人工开凿的登山路，天梯
青石铺就，上面雕花以防打滑，极为精致，显见得当年铺造之时花了无数的气力及
心血。一路走来，仔细观察，两边草丛之中居然有许多森森白骨，更有断刃残剑，
显然都是些武林中人，只是为何倒毙这里，令人难以理解。
LONG
        );
        set("exits", ([ 
  		"southwest" : __DIR__"gudi",
  		"northup" : __DIR__"tianti2",
	]));
	set("outdoors","laowu");
	set("coor/x",160);
	set("coor/y",180);
	set("coor/z",10);
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
	tell_object(me,"你什么也没找到。\n");
      	me->start_busy(1);
      	return 1;
}