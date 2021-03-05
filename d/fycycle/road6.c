inherit ROOM;
void create()
{
        set("short", "城东小道");
        set("long", @LONG
这是风云城东的一条小道，也是从无名小镇去往风云城的必经之路。路上倒也
有不少行人。路边的护城河中流水声不绝。向东望去，是一座暗红色的山峰，上山
的道路就在南面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 	 "south" :	__DIR__"fyeast",
  	"northwest" : __DIR__"road5",
]));
        set("outdoors", "fengyun");


	set("coor/x",320);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_north", "enter");	// annie: no hint here since i assume they pass from the other side 1st.
}



int do_north(string arg)
{
    object room, me;
		me = this_player();
		if (!room= find_object("/d/fy/stone2"))
			room=load_object("/d/fy/stone2");
		tell_object(me,"\n你想起韩信他年且受胯下之辱，相较下你这堂堂大侠钻个把儿狗洞又算什么。\n");
		me->ccommand("emote 小心翼翼地跋过护城河，一低身便向城墙上的一个狗洞钻去。\n");
		me->move(room);
		me->ccommand("emote 嘿嘿一笑，从狗洞中钻了出来，拍了拍手。");
		if (!REWARD_D->check_m_success(me,"狗洞大侠"))
				REWARD_D->riddle_done(me,"狗洞大侠",1,1);
		me->set_temp("body_print", "这人身上沾满了黑泥灰水，还滴滴答答地正向下落，\n看起来好恶心啊。");
		return 1;
}

