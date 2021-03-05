
// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
void create()
{
        set("short", "铜人坑");
        set("long", @LONG
你正站在一个坑中，四周的坡子上是形态各异的铜人，地面上杂七杂八的丢弃
着许许多多残断的铜人肢体，你忽然想起南少林蝉梦大师北上嵩山协作＂铜人巷＂
未成败返的江湖传说．．．
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gaoroom",
  "west" : __DIR__"kuoran",
]));
        set("outdoors", "shaolin");
	set("no_fly",1);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init()
{
	delete("exits");
	if(userp(this_player()))
		call_out("attack",3,this_player(),1);
}

int attack(object me,int count)
{
	object muren;
	muren= new(__DIR__"npc/bronzefighter");
	muren->move(this_object());
	if (environment(me)!=this_object())
		return 1;
	message_vision("一组铜人向$N滑来！",me);
	muren->do_perform(me,count);
	me->set_temp("last_damage_from","私探少林铜人坑，死于不测。");
	if(present(me,this_object()) && count < 10){
		destruct(muren);
		count++;
		message_vision("铜人滑过，退到一旁．．．\n",me);
		call_out("attack",1+random(2),me,count);
	}
	else	{
		destruct(muren);
		message_vision("\n一左一右两扇铜门忽尔打开．．．\n\n",me);
		set("exits/west", __DIR__"kuoran");
		set("exits/east", __DIR__"gaoroom");
		me->delete_temp("last_damage_from");
	}
}

