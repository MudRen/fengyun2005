// Room: fodian.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "佛殿");

	set("long", @LONG
殿中空空如也。也没有人，无论死活都没有，只有殿前的炉鼎中正在散发着淡
黄色的烟雾。佛殿里的塑像都是那阴阳怪气、半死不活的样子，尤其在这种凄迷的
烟雾里，看来更令人觉得可怕。一阵风从外面吹进来，吹得佛殿里的烟雾漂渺四散，
那些阴阳怪气、半死不活的泥像，在飘散的烟雾中看来，就像是忽然全都变成了活
的，正在那里张牙舞爪，等着择人而噬。后面似乎还个扇小门。
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"south":__DIR__"bigyard",
	]) );
	set("item_desc",([
		"炉鼎":"一个青烟缭绕的炉鼎，似乎可以搬动（move）。\n",
		"luding":"一个青烟缭绕的炉鼎，似乎可以搬动（move）。\n",
		]));
	//}}
        set("indoors", "shanliu");
	set("objects", ([
	__DIR__"npc/monk2" :1,
	]) );
	set("coor/x",-2);
	set("coor/y",60);
	set("coor/z",60);
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me;
	object monk;
	if (!arg || (arg != "炉鼎" && arg != "luding"))
	{
		return 0;
	}
	me=this_player();
	if (!mapp(me->query("organization")) || (string)me->query("organization/org_name")!="山流")
	{
		if (monk = present("old monk",this_object()))
		{
			 message_vision("$N双手合十对$n道：施主非山流中人，还是请回吧。\n",monk,me);
			 return 1;
		}
	}
	if (me->query("force_factor")<=50)
	{
		return notify_fail("你内力不够\n");
	}
	message_vision("佛殿中突然露出个黑黑的暗道，$N身影一闪，钻进了暗道。\n",me);
	me->move(__DIR__"mishi");
	//message_vision("眨眼间,暗道消失得无影无踪,一切好像只是你的想象。\n");
	tell_object(me,"你顿觉脚下腾空，转瞬间竟已掉到了间小屋中。\n");
	message_vision("$N从空中掉了下来。\n",me);
	return 1;
}
