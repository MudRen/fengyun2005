// Tie@fy3
inherit ROOM;

void create()
{
	set("short", "奥斯维刑集中营");
	set("long", @LONG
这里是处理程序中不能立刻destruct NPC的地方，NPC到达此处后，将在一分钟
后消失。如果是物品，则将在正常刷新时消失。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	]));
        set("no_fight", 1);
		set("no_magic", 1);

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",-10000);
	setup();
}

void byebye(object me){
	if (!me)	return;
	if (environment(me)!= this_object())	return;
	destruct(me);
	return;
}	
		

void init(){

	object owner, me = this_player();
	if (userp(me))	return;
	if (objectp(owner = me->query("possessed")))
	if (userp(owner))	return;

	me->delete("can_fly");
	call_out("byebye", 60, me);
}


			
		
		