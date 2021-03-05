// Room: nilu1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "泥土山路");

	set("long", @LONG
这是条泥土路，似乎刚下过雨，山路也格外泥泞难行，你低一脚高一脚往前努
力走着，不一会便气喘吁吁，汗流夹背了。前面不远似乎人烟嘈杂，有家店铺，愈
往前走，山雾就愈来愈大，到后来几乎无法辩得清眼前的东西了。
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"northup":__DIR__"qigeban",
	"eastdown":__DIR__"nilu2",
	]) );
	//}}
		set("objects", ([
                __DIR__"npc/tianzong3" : 1,
       ]) );
        set("outdoors", "shanliu");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
void init()
{
	object me;
	if (interactive(me=this_player()) && userp(me) && (me->query_temp("入山流/送东西") || (mapp(me->query("organization")) && (string)me->query("organization/org_name")=="山流")))
	{
		remove_call_out("killshanliu");
        call_out("killshanliu", 1, me);
	}
}
void killshanliu(object me)
{
	object ayan;
	if( !me || environment(me) != this_object() ) return;
	ayan = present("tianwu yan",this_object());
	if (!ayan)
	{
		ayan = new(__DIR__"npc/tianzong3");
		ayan->move(this_object());
		message_vision("$N眼前忽然一花，一道人影出现在面前。\n",me);
	}
	ayan->ccommand("rascal tianwu yan");
	ayan->kill_ob(me);
}

int valid_leave(object me, string dir)
{
	
	object assassinator;
	if (me->query_temp("入山流/送东西"))
	{
		if ((assassinator = present("tianwu yan",this_object())) && dir == "northup")
		{
			return notify_fail(assassinator->name()+"长剑斜指，拦住去路，冷声道：想走，先杀了我。\n");
			//return notify_fail("no up");
		}
	}		

	if (random(6))
	{
		tell_object(me,"山路也格外泥泞难行，你低一脚高一脚往前努力走着\n");
		return notify_fail("");
	}			
	return 1;
}


