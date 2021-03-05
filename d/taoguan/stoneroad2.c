// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
        set("short", "青石小径");
        set("long", @LONG
小径的一侧是一栋木造两层高的屋子。屋子四周的门窗都紧紧的关著, 门口上
方挂著一方蓝色琉璃匾额, 上书[33m『太清殿』[32m三个金字，门旁立著一个石碑。小径再
往前通向一个寂静的院落，院门半开着。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad",
            "north" : __DIR__"book_room1",
            "northwest": __DIR__"bieyuan",
	]));
        set("outdoors", "taoguan");
        set("item_desc", ([
            "bei" : "石碑上写著 : \n\n"
                     "    非\n"
                     "    三  不\n"
                     "    清  得\n"
                     "    弟  进\n"
                     "    子  入\n\n石碑上的一些青苔有被人擦过的痕迹，你也许可以试着推推看（push）。\n\n",
            "石碑" : "石碑上写著 : \n\n"
                     "    非\n"
                     "    三  不\n"
                     "    清  得\n"
                     "    弟  进\n"
                     "    子  入\n\n石碑上的一些青苔有被人擦过的痕迹，你也许可以试着推推看（push）。\n\n"
           ]) );

	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, room;
	int i,flag=0;
	string *msg = ({
"非","三","清","弟","子","不","得","进","入",
});

   	me = this_player();


	if (!arg || (arg != "bei" && arg != "石碑"
		&& member_array(arg, msg) == -1 ))
		return notify_fail("你要推什么？\n");

	if (REWARD_D->riddle_check(me,"无字天书") != 5 
		&& !REWARD_D->check_m_success(me,"风林火山")) // 有了三弟随时都可以来推
		return notify_fail("
石碑摇了摇，上面的字似乎动了几下，你赶紧揉了揉眼睛，
石碑还是站在那里，冷冷地盯着你，周围还是死寂一片。\n");

	if (arg == "bei" || arg == "石碑") 
		return notify_fail("
石碑摇了摇，上面的字似乎动了几下，你赶紧揉了揉眼睛，
石碑还是站在那里，冷冷地盯着你，周围还是死寂一片。\n");

	for (i=0;i<9 ;i++ )
	{
		if (arg == msg[i])
		{
			if (query(("flag/"+(i+1))) == 1)
			{
				tell_object(me,"写有＂"+arg+"＂字的石块已经陷进去了。\n");
				return 1;
			}
/*			else
				tell_object(me,"写有＂"+query("flag/"+i+1)+"＂字的石块已经陷进去了。"+"flag/"+(i+1));
*/
			if (i != 1 && i != 3)
			{
				me->set_temp("annie/demon_taoguanstone",0);
			}
			else if (i == 1)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=1)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",2);
			}
			else if (i == 3)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=0)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",1);
			}
			message_vision(CYN"$N伸出手，在石碑的＂"+arg+"＂字上推了一下。\n写有＂"+arg+"＂字的石块缓缓的缩了进去。\n"NOR,me);
			flag = i+1;
		}
	}
	if (flag)
	{
		set("flag/"+flag,1);
		call_out("do_eject",2,me,flag);
		return 1;
	}
		return notify_fail("你要推什么？");
}


void do_eject(object me,int flag)
{
	string *msg = ({
"非","三","清","弟","子","不","得","进","入",
});
	set("flag/"+flag,0);
	if (me->query_temp("annie/demon_taoguanstone") == 2 && environment(me) == this_object())
	{
		tell_object(me,CYN"石碑上写有＂三＂字的石块缓缓的滑了出来。\n"NOR);
		tell_object(me,CYN"石碑上写有＂弟＂字的石块缓缓的滑了出来。\n"NOR);
		me->set_temp("annie/demon_taoguanstone",0);
		message_vision(CYN"\n只听＂咯啦＂一响，石碑忽然整个向旁边滑开三尺。\n"NOR,me);
		message_vision(CYN"$N措手不及，整个人摔了下去。\n"NOR,me);
		me->move(load_object(__DIR__"secretpath1"));
		if (me->query("kee") > 300)
			me->receive_wound("kee",300);
		else me->unconcious();
		message_vision(CYN"$N＂啪嗒＂一声掉了下来。\n"NOR,me);
		tell_room(this_object(),"石碑缓缓的滑回原位，仿佛什么也没有发生过。\n");
		tell_room(this_object(),CYN"石碑上写有＂三＂字的石块缓缓的滑了出来。\n"NOR);
		return;		
	}
	me->set_temp("annie/demon_taoguanstone",0);
	tell_room(this_object(),CYN"石碑上写有＂"+msg[flag-1]+"＂字的石块缓缓的滑了出来。\n"NOR);
	return;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

